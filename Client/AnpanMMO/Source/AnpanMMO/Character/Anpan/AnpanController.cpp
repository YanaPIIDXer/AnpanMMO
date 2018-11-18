// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "AnpanController.h"
#include "Anpan.h"

// コンストラクタ
AAnpanController::AAnpanController(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
	, pAnpan(nullptr)
	, MoveTarget(FVector::ZeroVector)
	, PrevPos(FVector::ZeroVector)
	, MoveTime(0.0f)
	, MoveStartTime(0.0f)
	, RotateTarget(0.0f)
	, PrevRotate(0.0f)
	, RotateTime(0.0f)
	, RotateStartTime(0.0f)
{
}

// Pawnが紐付けられた。
void AAnpanController::Possess(APawn *aPawn)
{
	Super::Possess(aPawn);

	pAnpan = Cast<AAnpan>(aPawn);
	check(pAnpan != nullptr);
}

// 毎フレームの処理.
void AAnpanController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UpdateMove(DeltaTime);
	UpdateRotation(DeltaTime);
}

// 移動.
void AAnpanController::Move(float X, float Y, float Z, int32 Time)
{
	if (MoveTime > 0.0f)
	{
		pAnpan->SetActorLocation(MoveTarget);
	}

	PrevPos = pAnpan->GetActorLocation();
	MoveTarget = FVector(X, Y, Z);
	MoveTime = Time / 1000.0f;
	MoveStartTime = MoveTime;
}

// 回転.
void AAnpanController::Rotate(float Rotation, int32 Time)
{
	if (RotateTime > 0.0f)
	{
		pAnpan->SetActorRotation(FRotator(0.0f, RotateTarget, 0.0f));
	}

	PrevRotate = pAnpan->GetActorRotation().Yaw;
	RotateTarget = Rotation;
	RotateTime = Time / 1000.0f;
	RotateStartTime = RotateTime;
}

// 停止.
void AAnpanController::Stop(float X, float Y, float Z, float Rotation)
{
	MoveTime = 0.0f;
	RotateTime = 0.0f;

	/*
	FVector Pos = FVector(X, Y, Z);
	FRotator Rot(0.0f, Rotation, 0.0f);
	pAnpan->SetActorLocationAndRotation(Pos, Rot);
	*/
}


// 移動更新.
void AAnpanController::UpdateMove(float DeltaTime)
{
	if (MoveTime <= 0.0f) { return; }

	MoveTime -= DeltaTime;
	if (MoveTime <= 0.0f)
	{
		MoveTime = 0.0f;
		pAnpan->SetActorLocation(MoveTarget);
		return;
	}

	FVector Pos = FMath::Lerp<FVector>(PrevPos, MoveTarget, 1.0f - (MoveTime / MoveStartTime));
	pAnpan->SetActorLocation(Pos);
}

// 回転更新.
void AAnpanController::UpdateRotation(float DeltaTime)
{
	if (RotateTime <= 0.0f) { return; }

	RotateTime -= DeltaTime;
	if (RotateTime <= 0.0f)
	{
		RotateTime = 0.0f;
		pAnpan->SetActorRotation(FRotator(0.0f, RotateTarget, 0.0f));
		return;
	}

	float Rot = FMath::Lerp<float>(PrevRotate, RotateTarget, 1.0f - (RotateTime / RotateStartTime));
	pAnpan->SetActorRotation(FRotator(0.0f, Rot, 0.0f));
}
