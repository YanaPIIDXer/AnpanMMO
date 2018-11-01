// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "TitleGameMode.h"
#include "MMOGameInstance.h"

// �R���X�g���N�^
ATitleGameMode::ATitleGameMode(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// �Q�[���T�[�o�ւ̐ڑ�.
void ATitleGameMode::ConnectToGameServer()
{
	UMMOGameInstance *pInst = Cast<UMMOGameInstance>(GetGameInstance());
	check(pInst != nullptr);

	if (!pInst->Connect("127.0.0.1", 4424))
	{
		UE_LOG(LogTemp, Log, TEXT("GameServer Connection Failed..."));
	}
}
