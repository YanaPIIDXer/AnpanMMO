// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "GameController.h"
#include "Engine/World.h"

// �R���X�g���N�^
AGameController::AGameController(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
	, pCamera(nullptr)
{
}

// Pawn���R�t����ꂽ�B
void AGameController::Possess(APawn *aPawn)
{
	Super::Possess(aPawn);
	
	// �J�����𐶐�.
	FActorSpawnParameters Param;
	Param.bNoFail = true;
	Param.Owner = this;
	Param.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	pCamera = GetWorld()->SpawnActor<AGameCamera>(AGameCamera::StaticClass(), Param);
	SetViewTargetWithBlend(pCamera.Get());

	auto *pPlayer = Cast<AGameCharacter>(aPawn);
	check(pPlayer != nullptr);
	pCamera->SetGameCharacter(pPlayer);
}
