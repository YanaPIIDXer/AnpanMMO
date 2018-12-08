// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "GameController.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "Active/ActiveGameMode.h"
#include "Active/UI/MainHUD.h"
#include "Engine/Public/DrawDebugHelpers.h"

class AOtherPlayerCharacter;

const FName AGameController::MoveForwardBind = "Forward";
const FName AGameController::MoveRightBind = "Right";
const FName AGameController::AttackBind = "Attack";
const float AGameController::TapCheckThreshold = 10.0f;

// コンストラクタ
AGameController::AGameController(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
	, pCharacter(nullptr)
	, pCamera(nullptr)
	, InputVector(FVector::ZeroVector)
	, PrevTouchLocation(FVector2D::ZeroVector)
	, bEnableMove(true)
	, SwipeValue(0.0f)
	, pCurrentTarget(nullptr)
	, bHasTarget(false)
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

// 毎フレームの処理.
void AGameController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MoveProc();

	if (bHasTarget && pCurrentTarget == nullptr)
	{
		// ターゲットにしていたキャラが消えた。
		bHasTarget = false;
		NoticeTargetChanged();
	}
}

// タッチ処理.
bool AGameController::InputTouch(uint32 Handle, ETouchType::Type Type, const FVector2D &TouchLocation, float Force, FDateTime DeviceTimestamp, uint32 TouchpadIndex)
{
	switch (Type)
	{
		case ETouchType::Began:

			SwipeValue = 0.0f;
			break;

		case ETouchType::Moved:

			{
				FVector2D Delta = TouchLocation - PrevTouchLocation;
				SwipeValue += FMath::Abs<float>(Delta.X);
				SwipeValue += FMath::Abs<float>(Delta.Y);
				if (bEnableMove)
				{
					pCamera->Rotate(Delta.X);
				}
			}
			break;

		case ETouchType::Ended:

			if (SwipeValue <= TapCheckThreshold)
			{
				RayTraceForTarget(TouchLocation);
			}
			break;
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

// 移動処理.
void AGameController::MoveProc()
{
	// ↓本来なら不要なNULLチェックなんだけど突如落ちるようになったので。
	if (pCharacter == nullptr) { return; }

	if (pCharacter->IsDead()) { return; }

	if (!bEnableMove) { return; }

	if (InputVector == FVector::ZeroVector) { return; }
	InputVector.Normalize();
	FRotator CameraRot = pCamera->GetActorRotation();
	CameraRot.Pitch = 0.0f;
	CameraRot.Roll = 0.0f;
	FVector Vec = CameraRot.RotateVector(InputVector);
	pCharacter->AddMovementInput(Vec);

	if (InputVector.SizeSquared() > 0.0f)
	{
		FRotator Rot = Vec.Rotation();
		pCharacter->SetActorRotation(Rot);
	}
}

// 前後移動.
void AGameController::MoveForward(float Value)
{
	InputVector.X = Value;
}

// 左右移動.
void AGameController::MoveRight(float Value)
{
	InputVector.Y = Value;
}

// ターゲットを決めるためのレイトレース
void AGameController::RayTraceForTarget(const FVector2D &ScreenPos)
{
	if (!bEnableMove) { return; }

	FVector Pos;
	FVector Direction;
	DeprojectScreenPositionToWorld(ScreenPos.X, ScreenPos.Y, Pos, Direction);

	AActiveGameMode *pGameMode = Cast<AActiveGameMode>(UGameplayStatics::GetGameMode(this));
	check(pGameMode != nullptr);

	FVector Start = Pos;
	FVector End = Pos + (Direction * 3000.0f);

	FHitResult Result;
	if (!GetWorld()->LineTraceSingleByChannel(Result, Start, End, ECollisionChannel::ECC_GameTraceChannel3))
	{
		if (bHasTarget)
		{
			if (pCurrentTarget != nullptr)
			{
				pCurrentTarget->DestroyTargetCircle();
			}

			pCurrentTarget = nullptr;
			bHasTarget = false;
			NoticeTargetChanged();
		}
		return;
	}

	ACharacterBase *pChara = Cast<ACharacterBase>(Result.GetActor());
	if (pChara != nullptr)
	{
		if (pChara != pCurrentTarget)
		{
			if (pCurrentTarget != nullptr)
			{
				pCurrentTarget->DestroyTargetCircle();
			}

			pCurrentTarget = pChara;
			pCurrentTarget->SpawnTargetCircle();
			bHasTarget = true;
			NoticeTargetChanged();
		}
	}
	else
	{
		if (bHasTarget)
		{
			if (pCurrentTarget != nullptr)
			{
				pCurrentTarget->DestroyTargetCircle();
			}

			pCurrentTarget = nullptr;
			bHasTarget = false;
			NoticeTargetChanged();
		}
	}
}

// ターゲット切り替え通知.
void AGameController::NoticeTargetChanged()
{
	AActiveGameMode *pGameMode = Cast<AActiveGameMode>(UGameplayStatics::GetGameMode(this));
	check(pGameMode != nullptr);

	pGameMode->GetMainHUD()->OnTargetChanged(pCurrentTarget.Get());
}
