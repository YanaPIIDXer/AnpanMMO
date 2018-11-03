// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "ActiveGameMode.h"
#include "MMOGameInstance.h"

// �R���X�g���N�^
AActiveGameMode::AActiveGameMode(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// �J�n���̏���.
void AActiveGameMode::BeginPlay()
{
	Super::BeginPlay();

	auto *pInst = Cast<UMMOGameInstance>(GetGameInstance());
	check(pInst != nullptr);
	pInst->OnRecvPacketDelegate.BindUObject(this, &AActiveGameMode::OnRecvPacket);
}


// �p�P�b�g����M�����B
void AActiveGameMode::OnRecvPacket(PacketID ID, MemoryStreamInterface *pStream)
{

}
