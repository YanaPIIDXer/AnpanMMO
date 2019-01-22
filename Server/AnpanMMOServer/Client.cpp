/**
 * @file Client.h
 * @brief �N���C�A���g�N���X
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

// �R���X�g���N�^
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

// �f�X�g���N�^
Client::~Client()
{
}

// �p�P�b�g���M.
void Client::SendPacket(PacketBase *pPacket)
{
	//�܂��̓T�C�Y�����߂�
	MemorySizeCaliculateStream SizeStream;
	pPacket->Serialize(&SizeStream);

	//�V���A���C�Y�{��
	MemoryStreamWriter WriteStream(SizeStream.GetSize() + 3);

	u8 Id = (u8)pPacket->GetPacketID();
	u16 Size = SizeStream.GetSize();
	WriteStream.Serialize(&Id);
	WriteStream.Serialize(&Size);
	pPacket->Serialize(&WriteStream);

	//���M
	AsyncSend(WriteStream.GetStream(), WriteStream.GetSize());
}

// �X�e�[�g�؂�ւ�
void Client::ChangeState(ClientStateBase *pNextState)
{
	pState = shared_ptr<ClientStateBase>(pNextState);
	pState->BeginState();
}

// �L�����N�^�쐬.
void Client::CreateCharacter(u32 CharacterId, const std::string &Name, u8 Job, u32 Level, u32 Exp, u32 Gold, u32 RightEquipId, u32 LeftEquipId)
{
	PlayerCharacter *pChara= new PlayerCharacter(this, CharacterId, Job, Level, Exp, Gold, RightEquipId, LeftEquipId);
	pChara->SetUuid(Uuid);
	pChara->SetName(Name);
	pCharacter = shared_ptr<PlayerCharacter>(pChara);
}

// �p�P�b�g����M.
void Client::RecvPacket(u8 ID, MemoryStreamInterface *pStream)
{
	pStream->Reset();
	pState->AnalyzePacket(ID, pStream);
}

// �X�N���v�g�t���O��ݒ�.
void Client::SetScriptFlag(int Key)
{
	FlagManager.Set(Key);
}

// �r�b�g�t�B�[���h����X�N���v�g�t���O�ɕϊ�.
void Client::ConvertScriptFlagFromBitFields(u32 BitField1, u32 BitField2, u32 BitField3)
{
	FlagManager.FromBitField(BitField1, BitField2, BitField3);
}

// �N�G�X�g�f�[�^�ǉ�.
void Client::AddQuestData(const QuestData &Data)
{
	QuestMgr.Add(Data);
}

// �N�G�X�g��.
void Client::AcceptQuest(u32 QuestId)
{
	QuestMgr.Accept(QuestId);
}

// �N�G�X�g�i�s.
void Client::ProgressQuest(u32 QuestId)
{
	QuestMgr.ProgressStage(QuestId);
}

// �A���p�����E�Q�����B
void Client::OnKilledAnpan(u32 AreaId)
{
	QuestMgr.OnKilledAnpan(AreaId);
}

// �N�G�X�g�j��.
u8 Client::RetireQuest(u32 QuestId)
{
	return QuestMgr.Retire(QuestId);
}

// �A�C�e���w��.
u8 Client::BuyItem(u32 ShopId, u32 ItemId, u32 Count)
{
	// �L���ȃV���b�v���H
	if (Script.GetCurrentShopId() != ShopId || !ShopManager::GetInstance().IsValidShop(ShopId)) { return PacketBuyItemResult::InvalidShopId; }

	// �����Ă��邩�H
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

	// ��������邩�H
	u32 BuyGold = ItemBuyGold * Count;
	if (pCharacter->GetGold() < BuyGold) { return PacketBuyItemResult::NotEnougthGold; }

	// �w������.
	pCharacter->SubtractGold(BuyGold);
	pCharacter->AddItem(ItemId, Count);

	return PacketBuyItemResult::Success;
}

// �A�C�e�����p.
u8 Client::SellItem(u32 ShopId, u32 ItemId, u32 Count)
{
	// �L���ȃV���b�v���H
	if (Script.GetCurrentShopId() != ShopId) { return PacketSellItemResult::InvalidShopId; }

	// �A�C�e���͏������Ă��邩�H
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

	// ���p����.
	pCharacter->SubtractItem(ItemId, Count);
	pCharacter->AddGold(ItemSellGold * Count);

	return PacketSellItemResult::Success;
}


// �f�[�^����M�����B
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
