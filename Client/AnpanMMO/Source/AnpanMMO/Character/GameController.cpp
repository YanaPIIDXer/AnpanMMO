// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "GameController.h"
#include "Engine/World.h"

const FName AGameController::MoveForwardBind = "Forward";
const FName AGameController::MoveRightBind = "Right";

// �R���X�g���N�^
AGameController::AGameController(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
	, pCharacter(nullptr)
	, pCamera(nullptr)
{
}

// Pawn���R�t����ꂽ�B
void AGameController::Possess(APawn *aPawn)
{
	Super::Possess(aPawn);
	
	SpawnCamera();

	auto *pPlayer = Cast<AGameCharacter>(aPawn);
	check(pPlayer != nullptr);
	pCamera->SetGameCharacter(pPlayer);
	pCharacter = pPlayer;

	SetupPlayerInput(pPlayer->InputComponent);
}


// �J������Spawn
void AGameController::SpawnCamera()
{
	FActorSpawnParameters Param;
	Param.bNoFail = true;
	Param.Owner = this;
	Param.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	pCamera = GetWorld()->SpawnActor<AGameCamera>(AGameCamera::StaticClass(), Param);
	SetViewTargetWithBlend(pCamera.Get());
}

// PlayerInputComponent�̃Z�b�g�A�b�v
void AGameController::SetupPlayerInput(UInputComponent *pInputComponent)
{
	check(pInputComponent != nullptr);

	pInputComponent->BindAxis(MoveForwardBind, this, &AGameController::MoveForward);
	pInputComponent->BindAxis(MoveRightBind, this, &AGameController::MoveRight);
}

// �O��ړ�.
void AGameController::MoveForward(float Value)
{
}

// ���E�ړ�.
void AGameController::MoveRight(float Value)
{
}
