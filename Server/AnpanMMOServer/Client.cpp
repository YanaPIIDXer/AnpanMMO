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
void Client::CreateCharacter(u32 CharacterId, const std::string &Name, u8 Job, u32 Level, int MaxHp, int Atk, int Def, int Exp, u32 Gold)
{
	PlayerCharacter *pChara= new PlayerCharacter(this, CharacterId, Job, Level, MaxHp, Atk, Def, Exp, Gold);
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
