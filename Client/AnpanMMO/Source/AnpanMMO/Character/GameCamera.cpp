// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "GameCamera.h"

// コンストラクタ
AGameCamera::AGameCamera(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
	, pPlayer(nullptr)
{
	PrimaryActorTick.bCanEverTick = true;
}

// 毎フレームの処理.
void AGameCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SetActorLocation(pPlayer->GetActorLocation());
}
