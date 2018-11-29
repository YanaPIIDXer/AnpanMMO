// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "GameCamera.h"

const float AGameCamera::DistanceFromPlayer = 500.0f;

// �R���X�g���N�^
AGameCamera::AGameCamera(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
	, pPlayer(nullptr)
	, Rotation(0.0f, 0.0f, 0.0f)
{
	PrimaryActorTick.bCanEverTick = true;
}

// ���t���[���̏���.
void AGameCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// �����̂��˔@������悤�ɂȂ����B
	//   PlayerController��Possess������O��Tick������悤�ɂȂ����̂��Ǝv���邪
	//   �����Ȃ��������͕s���B
	if (pPlayer == nullptr) { return; }

	FVector PlayerPos = pPlayer->GetActorLocation();
	FVector BackVec = FVector(-DistanceFromPlayer, 0.0f, 150.0f);
	BackVec = Rotation.RotateVector(BackVec);
	SetActorLocation(PlayerPos + BackVec);

	FVector Vec = PlayerPos - GetActorLocation();
	FRotator Rot = Vec.Rotation();
	SetActorRotation(Rot);
}

// ��].
void AGameCamera::Rotate(float Yaw)
{
	Rotation.Yaw += Yaw;
}
