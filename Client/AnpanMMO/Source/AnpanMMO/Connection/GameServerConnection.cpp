// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "GameServerConnection.h"
#include "MemoryStream/MemoryStreamReader.h"
#include "Packet/PacketHeader.h"
#include "Packet/PacketBase.h"
#include "MemoryStream/MemorySizeCaliculateStream.h"
#include "MemoryStream/MemoryStreamWriter.h"

const int GameServerConnection::RecvDataSize = 1024;

// コンストラクタ
GameServerConnection::GameServerConnection()
	: pSocket(nullptr)
{
}

// デストラクタ
GameServerConnection::~GameServerConnection()
{
	Close();
}

// 接続.
bool GameServerConnection::Connect(const FString &Host, int32 Port)
{
	if (pSocket != nullptr)
	{
		// そのままreturnの方がいい・・・？
		Close();
	}

	pSocket = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateSocket(NAME_Stream, "GameServerConnection");
	if (pSocket == nullptr) { return false; }

	TSharedRef<FInternetAddr> Addr = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
	bool bIsValidHost = false;
	Addr->SetIp(*Host, bIsValidHost);
	Addr->SetPort(Port);

	if (!pSocket->Connect(Addr.Get())) { return false; }

	pSocket->SetNonBlocking(true);
	return true;
}

// 切断.
void GameServerConnection::Close()
{
	if (pSocket == nullptr) { return; }
	
	pSocket->Close();
	ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->DestroySocket(pSocket);
	pSocket = nullptr;
}

// パケット送信.
void GameServerConnection::SendPacket(PacketBase *pPacket)
{
	//まずはサイズを求める
	MemorySizeCaliculateStream SizeStream;
	pPacket->Serialize(&SizeStream);

	//シリアライズ本番
	MemoryStreamWriter WriteStream(SizeStream.GetSize() + 2);

	u8 Id = (u8)pPacket->GetPacketID();
	u8 Size = SizeStream.GetSize();
	WriteStream.Serialize(&Id);
	WriteStream.Serialize(&Size);
	pPacket->Serialize(&WriteStream);
	
	const u8 *pData = WriteStream.GetStream();
	SendBuffer.Push(pData, WriteStream.GetSize());
}

// 毎フレームの処理.
void GameServerConnection::Tick(float DeltaTime)
{
	if (!IsConnected()) { return; }

	SendProc();
	RecvProc();
}


// 送信処理.
void GameServerConnection::SendProc()
{
	uint8 *pData = SendBuffer.GetTop();
	int32 Size = SendBuffer.GetSize();
	int32 SendSize = 0;
	if (!pSocket->Send(pData, Size, SendSize) || SendSize <= 0) { return; }
	SendBuffer.Pop(SendSize);
}

// 受信処理.
void GameServerConnection::RecvProc()
{
	uint8 RecvData[RecvDataSize];
	int32 RecvSize = 0;

	if (!pSocket->Recv(&RecvData[0], RecvDataSize, RecvSize) || RecvSize <= 0) { return; }
	RecvBuffer.Push(&RecvData[0], RecvSize);

	uint8 *pData = RecvBuffer.GetTop();
	if (pData == nullptr) { return; }

	MemoryStreamReader StreamReader(pData, RecvBuffer.GetSize());
	PacketHeader Header;
	if (Header.Serialize(&StreamReader) && RecvBuffer.GetSize() >= Header.GetPacketSize())
	{
		RecvBuffer.Pop(2);

		MemoryStreamReader BodyStream(RecvBuffer.GetTop(), Header.GetPacketSize());
		OnRecvPacketDelegate.ExecuteIfBound(Header.GetPacketId(), &BodyStream);

		RecvBuffer.Pop(Header.GetPacketSize());
	}
}
