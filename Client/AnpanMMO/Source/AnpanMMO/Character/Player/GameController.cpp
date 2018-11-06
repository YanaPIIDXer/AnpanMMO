// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "GameController.h"
#include "Engine/World.h"

const FName AGameController::MoveForwardBind = "Forward";
const FName AGameController::MoveRightBind = "Right";
const FName AGameController::AttackBind = "Attack";

// コンストラクタ
AGameController::AGameController(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
	, pCharacter(nullptr)
	, pCamera(nullptr)
	, PrevTouchLocation(FVector2D::ZeroVector)
{
}

// Pawnが紐付けられた。
void AGameController::Possess(APawn *aPawn)
{
	Super::Possess(aPawn);
	
	SpawnCamera();

	pCharacter = Cast<AGameCharacter>(aPawn);
	check(pCharacter != nullptr);
	pCamera->SetGameCharacter(pCharacter.Get());
	
	SetupPlayerInput(pCharacter->InputComponent);
}

// タッチ処理.
bool AGameController::InputTouch(uint32 Handle, ETouchType::Type Type, const FVector2D &TouchLocation, float Force, FDateTime DeviceTimestamp, uint32 TouchpadIndex)
{
	if (Type == ETouchType::Moved)
	{
		FVector2D Delta = TouchLocation - PrevTouchLocation;
		pCamera->Rotate(Delta.X);
	}

	PrevTouchLocation = TouchLocation;
	return true;
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
	pInputComponent->BindAction(AttackBind, EInputEvent::IE_Pressed, pCharacter.Get(), &AGameCharacter::Attack);
}

// 前後移動.
void AGameController::MoveForward(float Value)
{
	if (Value == 0.0f) { return; }
	FVector Vec(Value, 0.0f, 0.0f);
	Vec = pCamera->GetActorRotation().RotateVector(Vec);

	FRotator Rot = Vec.Rotation();
	Rot.Yaw -= 90.0f;
	pCharacter->SetActorRotation(Rot);
	pCharacter->AddMovementInput(Vec);
}

// 左右移動.
void AGameController::MoveRight(float Value)
{
	if (Value == 0.0f) { return; }
	FVector Vec(0.0f, Value, 0.0f);
	Vec = pCamera->GetActorRotation().RotateVector(Vec);

	FRotator Rot = Vec.Rotation();
	Rot.Yaw -= 90.0f;
	pCharacter->SetActorRotation(Rot);
	pCharacter->AddMovementInput(Vec);
}
