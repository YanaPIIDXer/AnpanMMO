// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "GameServerConnection.h"

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

}
