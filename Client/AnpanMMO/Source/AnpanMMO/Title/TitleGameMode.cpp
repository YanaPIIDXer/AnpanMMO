// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "TitleGameMode.h"
#include "Title/UI/TitleScreenWidget.h"
#include "MMOGameInstance.h"
#include "MemoryStream/MemoryStreamInterface.h"

// �R���X�g���N�^
ATitleGameMode::ATitleGameMode(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// �J�n���̏���.
void ATitleGameMode::BeginPlay()
{
	Super::BeginPlay();

	auto *pWidget = UTitleScreenWidget::Create(this);
	pWidget->AddToViewport();

	UMMOGameInstance *pInst = Cast<UMMOGameInstance>(GetGameInstance());
	check(pInst != nullptr);
	pInst->OnRecvPacketDelegate.BindUObject(this, &ATitleGameMode::OnRecvPacket);
}


// �p�P�b�g����M�����B
void ATitleGameMode::OnRecvPacket(PacketID ID, MemoryStreamInterface *pStream)
{
	UE_LOG(LogTemp, Log, TEXT("PacketID:%X"), ID);
}
