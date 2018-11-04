// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "GameController.h"
#include "Engine/World.h"

const FName AGameController::MoveForwardBind = "Forward";
const FName AGameController::MoveRightBind = "Right";

// コンストラクタ
AGameController::AGameController(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
	, pCharacter(nullptr)
	, pCamera(nullptr)
{
}

// Pawnが紐付けられた。
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


// カメラをSpawn
void AGameController::SpawnCamera()
{
	FActorSpawnParameters Param;
	Param.bNoFail = true;
	Param.Owner = this;
	Param.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	pCamera = GetWorld()->SpawnActor<AGameCamera>(AGameCamera::StaticClass(), Param);
	SetViewTargetWithBlend(pCamera.Get());
}

// PlayerInputComponentのセットアップ
void AGameController::SetupPlayerInput(UInputComponent *pInputComponent)
{
	check(pInputComponent != nullptr);

	pInputComponent->BindAxis(MoveForwardBind, this, &AGameController::MoveForward);
	pInputComponent->BindAxis(MoveRightBind, this, &AGameController::MoveRight);
}

// 前後移動.
void AGameController::MoveForward(float Value)
{
}

// 左右移動.
void AGameController::MoveRight(float Value)
{
}
