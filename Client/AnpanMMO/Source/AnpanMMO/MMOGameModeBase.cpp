// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "MMOGameModeBase.h"
#include "MMOGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "UI/Menu/LayeredMenuWidgetBase.h"

// �R���X�g���N�^
AMMOGameModeBase::AMMOGameModeBase(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
	, pCurrentMenu(nullptr)
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
void AMMOGameModeBase::AddPacketFunction(uint8 ID, const PacketFunc &Func)
{
	PacketFunctions[ID] = Func;
}


// �p�P�b�g����M�����B
void AMMOGameModeBase::OnRecvPacket(uint8 ID, MemoryStreamInterface *pStream)
{
	auto It = PacketFunctions.find(ID);
	if (It != PacketFunctions.end())
	{
		if (!It->second(pStream))
		{
			UE_LOG(LogTemp, Error, TEXT("PacketID:%X Serialize Failed..."), (int32)ID);
		}
	}

	if (pCurrentMenu != nullptr)
	{
		pCurrentMenu->OnRecvPacket(ID);
	}
}
