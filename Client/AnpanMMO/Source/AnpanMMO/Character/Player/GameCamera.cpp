// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "GameCamera.h"

const float AGameCamera::DistanceFromPlayer = 500.0f;

// コンストラクタ
AGameCamera::AGameCamera(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
	, pPlayer(nullptr)
	, Rotation(0.0f, 0.0f, 0.0f)
{
	PrimaryActorTick.bCanEverTick = true;
}

// 毎フレームの処理.
void AGameCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// ↓何故か突如落ちるようになった。
	//   PlayerControllerのPossessが走る前にTickが走るようになったのかと思われるが
	//   そうなった原因は不明。
	if (pPlayer == nullptr) { return; }

	FVector PlayerPos = pPlayer->GetActorLocation();
	FVector BackVec = FVector(-DistanceFromPlayer, 0.0f, 150.0f);
	BackVec = Rotation.RotateVector(BackVec);
	SetActorLocation(PlayerPos + BackVec);

	FVector Vec = PlayerPos - GetActorLocation();
	FRotator Rot = Vec.Rotation();
	SetActorRotation(Rot);
}

// 回転.
void AGameCamera::Rotate(float Yaw)
{
	Rotation.Yaw += Yaw;
}
