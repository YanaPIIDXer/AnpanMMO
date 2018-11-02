// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "MMOGameInstance.h"

// コンストラクタ
UMMOGameInstance::UMMOGameInstance(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
	, pConnection(nullptr)
{
}

// 終了時の処理.
void UMMOGameInstance::Shutdown()
{
	Super::Shutdown();
	
	Close();
}

// 接続.
bool UMMOGameInstance::Connect(const FString &Host, int Port)
{
	pConnection = new GameServerConnection();
	if (!pConnection->Connect(Host, Port))
	{
		Close();
		return false;
	}
	return true;
}

// 切断.
void UMMOGameInstance::Close()
{
	if (pConnection == nullptr) { return; }

	delete pConnection;
	pConnection = nullptr;
}

// パケット送信.
void UMMOGameInstance::SendPacket(PacketBase *pPacket)
{
	check(pConnection != nullptr);

	pConnection->SendPacket(pPacket);
}
