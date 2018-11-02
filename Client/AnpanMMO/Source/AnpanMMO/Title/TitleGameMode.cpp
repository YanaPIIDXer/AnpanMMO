// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "TitleGameMode.h"
#include "Title/UI/TitleScreenWidget.h"
#include "MMOGameInstance.h"
#include "MemoryStream/MemoryStreamInterface.h"

// コンストラクタ
ATitleGameMode::ATitleGameMode(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// 開始時の処理.
void ATitleGameMode::BeginPlay()
{
	Super::BeginPlay();

	auto *pWidget = UTitleScreenWidget::Create(this);
	pWidget->AddToViewport();

	UMMOGameInstance *pInst = Cast<UMMOGameInstance>(GetGameInstance());
	check(pInst != nullptr);
	pInst->OnRecvPacketDelegate.BindUObject(this, &ATitleGameMode::OnRecvPacket);
}


// パケットを受信した。
void ATitleGameMode::OnRecvPacket(PacketID ID, MemoryStreamInterface *pStream)
{
	UE_LOG(LogTemp, Log, TEXT("PacketID:%X"), ID);
}
