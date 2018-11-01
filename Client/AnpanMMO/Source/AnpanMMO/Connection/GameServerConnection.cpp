// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "GameServerConnection.h"
#include "MemoryStream/MemoryStreamReader.h"
#include "Packet/PacketHeader.h"

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

	return true;
}

// 切断.
void GameServerConnection::Close()
{
	if (pSocket == nullptr) { return; }
	
	pSocket->Close();
	pSocket = nullptr;
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
	int32 Size = SendBuffer.GetSize();
	int32 SendSize = 0;
	pSocket->Send(SendBuffer.GetTop(), Size, SendSize);
	SendBuffer.Pop(SendSize);
}

// 受信処理.
void GameServerConnection::RecvProc()
{
	uint8 RecvData[1024];
	int32 RecvSize = 0;
	pSocket->Recv(&RecvData[0], 1024, RecvSize);
	RecvBuffer.Push(&RecvData[0], RecvSize);

	MemoryStreamReader StreamReader(RecvBuffer.GetTop(), RecvBuffer.GetSize());
	PacketHeader Header;
	if (Header.Serialize(&StreamReader) && RecvBuffer.GetSize() >= Header.GetPacketSize() + 2)
	{
		RecvBuffer.Pop(2);

		MemoryStreamReader BodyStream(RecvBuffer.GetTop(), Header.GetPacketSize());
		// @TODO:パケット解析処理.

		RecvBuffer.Pop(Header.GetPacketSize());
	}
}
