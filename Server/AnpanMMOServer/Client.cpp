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
{
	bIsConnected = true;
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
void Client::CreateCharacter(int MaxHp, int Atk, int Def, int Exp)
{
	PlayerCharacter *pChara= new PlayerCharacter(this, MaxHp, Atk, Def, Exp);
	pChara->SetUuid(Uuid);
	pCharacter = shared_ptr<PlayerCharacter>(pChara);
}


// データを受信した。
void Client::OnRecvData(size_t Size)
{
	u8 *pRecvData = RecvBuffer.GetTop();
	MemoryStreamReader ReadStream(pRecvData, Size);
	PacketHeader Header;
	if (Header.Serialize(&ReadStream) && RecvBuffer.GetSize() >= Header.GetPacketSize() + 3)
	{
		RecvBuffer.Pop(3);

		MemoryStreamReader BodyStream(RecvBuffer.GetTop(), Header.GetPacketSize());
		pState->AnalyzePacket(Header.GetPacketId(), &BodyStream);

		RecvBuffer.Pop(Header.GetPacketSize());
	}
}
