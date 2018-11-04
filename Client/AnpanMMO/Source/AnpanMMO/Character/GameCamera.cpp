// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "GameCamera.h"

// �R���X�g���N�^
AGameCamera::AGameCamera(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
	, pPlayer(nullptr)
{
	PrimaryActorTick.bCanEverTick = true;
}

// ���t���[���̏���.
void AGameCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SetActorLocation(pPlayer->GetActorLocation());
}
