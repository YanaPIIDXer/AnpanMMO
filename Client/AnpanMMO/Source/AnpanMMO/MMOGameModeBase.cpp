// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "MMOGameModeBase.h"
#include "MMOGameInstance.h"
#include "Kismet/GameplayStatics.h"

// �R���X�g���N�^
AMMOGameModeBase::AMMOGameModeBase(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{

}

// �J�n���̏���.
void AMMOGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	// �}�E�X�J�[�\����\������B
	UGameplayStatics::GetPlayerController(this, 0)->bShowMouseCursor = true;

	auto *pInst = Cast<UMMOGameInstance>(GetGameInstance());
	check(pInst != nullptr);
	pInst->OnRecvPacketDelegate.BindUObject(this, &AMMOGameModeBase::OnRecvPacket);
}


// �p�P�b�g��͊֐��ǉ�.
void AMMOGameModeBase::AddPacketFunction(PacketID ID, const PacketFunc &Func)
{
	PacketFunctions.Add(ID, Func);
}


// �p�P�b�g����M�����B
void AMMOGameModeBase::OnRecvPacket(PacketID ID, MemoryStreamInterface *pStream)
{
	if (PacketFunctions.Contains(ID))
	{
		PacketFunctions[ID](pStream);
	}
}
