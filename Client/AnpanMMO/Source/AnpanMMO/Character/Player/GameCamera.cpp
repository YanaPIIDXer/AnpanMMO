// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "GameCamera.h"

const float AGameCamera::DistanceFromPlayer = 300.0f;

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

	FVector PlayerPos = pPlayer->GetActorLocation();
	FVector BackVec = FVector(-DistanceFromPlayer, 0.0f, 0.0f);
	BackVec = Rotation.RotateVector(BackVec);
	SetActorLocation(PlayerPos + BackVec);
}
