/**
 * @file Client.h
 * @brief クライアントクラス
 * @author YanaP
 */

#include "stdafx.h"
#include "Client.h"
#include "Packet/PacketBase.h"
#include "MemoryStream/MemorySizeCaliculateStream.h"
#include "MemoryStream/MemoryStreamWriter.h"
#include "MemoryStream/MemoryStreamReader.h"
#include "Packet/PacketHeader.h"
#include "ClientState/ClientStateBase.h"
#include "ClientState/ClientStateTitle.h"
#include "Character/Player/PlayerCharacter.h"
#include "Shop/ShopManager.h"
#include "Master/MasterData.h"
#include "Packet/PacketBuyItemResult.h"
#include "Packet/PacketSellItemResult.h"

// コンストラクタ
Client::Client(const shared_ptr<tcp::socket> &pInSocket)
	: TCPConnection(pInSocket)
	, pState(new ClientStateTitle(this))
	, Uuid(0)
	, CustomerId(0)
	, QuestMgr(this)
{
	bIsConnected = true;
	Script.SetScriptDir("../../Script/Scripts");
	Script.SetClient(this);
	AsyncRecv();
}

// デストラクタ
Client::~Client()
{
}

// パケット送信.
void Client::SendPacket(PacketBase *pPacket)
{
	//まずはサイズを求める
	MemorySizeCaliculateStream SizeStream;
	pPacket->Serialize(&SizeStream);

	//シリアライズ本番
	MemoryStreamWriter WriteStream(SizeStream.GetSize() + 3);

	u8 Id = (u8)pPacket->GetPacketID();
	u16 Size = SizeStream.GetSize();
	WriteStream.Serialize(&Id);
	WriteStream.Serialize(&Size);
	pPacket->Serialize(&WriteStream);

	//送信
	AsyncSend(WriteStream.GetStream(), WriteStream.GetSize());
}

// ステート切り替え
void Client::ChangeState(ClientStateBase *pNextState)
{
	pState = shared_ptr<ClientStateBase>(pNextState);
	pState->BeginState();
}

// キャラクタ作成.
void Client::CreateCharacter(u32 CharacterId, const std::string &Name, u8 Job, u32 Level, u32 Exp, u32 Gold, u32 RightEquipId, u32 LeftEquipId)
{
	PlayerCharacter *pChara= new PlayerCharacter(this, CharacterId, Job, Level, Exp, Gold, RightEquipId, LeftEquipId);
	pChara->SetUuid(Uuid);
	pChara->SetName(Name);
	pCharacter = shared_ptr<PlayerCharacter>(pChara);
}

// パケットを受信.
void Client::RecvPacket(u8 ID, MemoryStreamInterface *pStream)
{
	pStream->Reset();
	pState->AnalyzePacket(ID, pStream);
}

// スクリプトフラグを設定.
void Client::SetScriptFlag(int Key)
{
	FlagManager.Set(Key);
}

// ビットフィールドからスクリプトフラグに変換.
void Client::ConvertScriptFlagFromBitFields(u32 BitField1, u32 BitField2, u32 BitField3)
{
	FlagManager.FromBitField(BitField1, BitField2, BitField3);
}

// クエストデータ追加.
void Client::AddQuestData(const QuestData &Data)
{
	QuestMgr.Add(Data);
}

// クエスト受注.
void Client::AcceptQuest(u32 QuestId)
{
	QuestMgr.Accept(QuestId);
}

// クエスト進行.
void Client::ProgressQuest(u32 QuestId)
{
	QuestMgr.ProgressStage(QuestId);
}

// アンパンを殺害した。
void Client::OnKilledAnpan(u32 AreaId)
{
	QuestMgr.OnKilledAnpan(AreaId);
}

// クエスト破棄.
u8 Client::RetireQuest(u32 QuestId)
{
	return QuestMgr.Retire(QuestId);
}

// アイテム購入.
u8 Client::BuyItem(u32 ShopId, u32 ItemId, u32 Count)
{
	// 有効なショップか？
	if (Script.GetCurrentShopId() != ShopId || !ShopManager::GetInstance().IsValidShop(ShopId)) { return PacketBuyItemResult::InvalidShopId; }

	// 売られているか？
	if (!ShopManager::GetInstance().IsSelling(ShopId, ItemId)) { return PacketBuyItemResult::NotSelling; }

	u32 ItemBuyGold = 0;
	if (ItemId < 10000)
	{
		const ItemItem *pItem = MasterData::GetInstance().GetItemMaster().GetItem(ItemId);
		if (pItem == NULL) { return PacketBuyItemResult::InvalidItem; }
		ItemBuyGold = pItem->BuyGold;
	}
	else
	{
		const EquipItem *pItem = MasterData::GetInstance().GetEquipMaster().GetItem(ItemId);
		if (pItem == NULL) { return PacketBuyItemResult::InvalidItem; }
		ItemBuyGold = pItem->BuyGold;
	}

	// 金が足りるか？
	u32 BuyGold = ItemBuyGold * Count;
	if (pCharacter->GetGold() < BuyGold) { return PacketBuyItemResult::NotEnougthGold; }

	// 購入処理.
	pCharacter->SubtractGold(BuyGold);
	pCharacter->AddItem(ItemId, Count);

	return PacketBuyItemResult::Success;
}

// アイテム売却.
u8 Client::SellItem(u32 ShopId, u32 ItemId, u32 Count)
{
	// 有効なショップか？
	if (Script.GetCurrentShopId() != ShopId) { return PacketSellItemResult::InvalidShopId; }

	// アイテムは所持しているか？
	if (pCharacter->GetItemList().GetCount(ItemId) < Count) { return PacketSellItemResult::NotHaveItem; }

	u32 ItemSellGold = 0;
	if (ItemId < 10000)
	{
		const ItemItem *pItem = MasterData::GetInstance().GetItemMaster().GetItem(ItemId);
		if (pItem == NULL) { return PacketSellItemResult::InvalidItem; }
		ItemSellGold = pItem->SellGold;
	}
	else
	{
		const EquipItem *pItem = MasterData::GetInstance().GetEquipMaster().GetItem(ItemId);
		if (pItem == NULL) { return PacketSellItemResult::InvalidItem; }
		ItemSellGold = pItem->SellGold;
	}

	// 売却処理.
	pCharacter->SubtractItem(ItemId, Count);
	pCharacter->AddGold(ItemSellGold * Count);

	return PacketSellItemResult::Success;
}


// データを受信した。
void Client::OnRecvData(size_t Size)
{
	u8 *pRecvData = RecvBuffer.GetTop();
	while (true)
	{
		MemoryStreamReader ReadStream(pRecvData, Size);
		PacketHeader Header;
		if (!Header.Serialize(&ReadStream) || RecvBuffer.GetSize() < Header.GetPacketSize() + 3) { break; }

		RecvBuffer.Pop(3);

		MemoryStreamReader BodyStream(RecvBuffer.GetTop(), Header.GetPacketSize());
		pState->AnalyzePacket(Header.GetPacketId(), &BodyStream);

		RecvBuffer.Pop(Header.GetPacketSize());
	}
}
