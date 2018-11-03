// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "ActiveGameMode.h"
#include "MMOGameInstance.h"

// コンストラクタ
AActiveGameMode::AActiveGameMode(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// 開始時の処理.
void AActiveGameMode::BeginPlay()
{
	Super::BeginPlay();

	auto *pInst = Cast<UMMOGameInstance>(GetGameInstance());
	check(pInst != nullptr);
	pInst->OnRecvPacketDelegate.BindUObject(this, &AActiveGameMode::OnRecvPacket);
}


// パケットを受信した。
void AActiveGameMode::OnRecvPacket(PacketID ID, MemoryStreamInterface *pStream)
{

}
