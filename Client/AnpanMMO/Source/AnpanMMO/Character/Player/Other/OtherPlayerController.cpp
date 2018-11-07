// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "OtherPlayerController.h"
#include "OtherPlayerCharacter.h"

const float AOtherPlayerController::MoveInterval = 5.0f;

// �R���X�g���N�^
AOtherPlayerController::AOtherPlayerController(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
	, MoveTarget(FVector::ZeroVector)
	, PrevPos(FVector::ZeroVector)
	, MoveTime(0.0f)
{
}


// Pawn���R�t����ꂽ�B
void AOtherPlayerController::Possess(APawn *aPawn)
{
	Super::Possess(aPawn);

	pCharacter = Cast<AOtherPlayerCharacter>(aPawn);
	check(pCharacter != nullptr);
}

// ���t���[���̏���.
void AOtherPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (MoveTime <= 0.0f) { return; }

	FVector Pos = FMath::Lerp<FVector>(PrevPos, MoveTarget, MoveTime / MoveInterval);
	pCharacter->SetActorLocation(Pos);
}

// �ړ�.
void AOtherPlayerController::Move(float X, float Y, float Rotation)
{
	pCharacter->SetActorRotation(FRotator(0.0f, Rotation, 0.0f));
	PrevPos = pCharacter->GetActorLocation();
	MoveTarget = PrevPos;
	MoveTarget.X = X;
	MoveTarget.Y = Y;

	MoveTime = MoveInterval;
}
