// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "MMOGameInstance.h"
#include "DLC/PakFileManager.h"

// コンストラクタ
UMMOGameInstance::UMMOGameInstance(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
	, pConnection(nullptr)
{
}

// 初期化時の処理.
void UMMOGameInstance::Init()
{
	Super::Init();

	PakFileManager::GetInstance().Initialize();
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

	pConnection->OnRecvPacketDelegate.BindUObject(this, &UMMOGameInstance::OnRecvPacket);
	
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

// ステータスを受信した。
void UMMOGameInstance::OnRecvStatus(uint32 Uuid, int32 MaxHp, int32 Atk, int32 Def, int32 Exp)
{
	StatusCache.SetUuid(Uuid);
	StatusCache.Set(MaxHp, Atk, Def);
	StatusCache.SetExp(Exp);
}


// パケットを受信した。
void UMMOGameInstance::OnRecvPacket(PacketID ID, MemoryStreamInterface *pStream)
{
	OnRecvPacketDelegate.ExecuteIfBound(ID, pStream);
}
