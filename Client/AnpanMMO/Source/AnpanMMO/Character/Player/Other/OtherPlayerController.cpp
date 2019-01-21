// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#include "OtherPlayerController.h"
#include "OtherPlayerCharacter.h"

const float AOtherPlayerController::MoveInterval = 2.0f;

// �R���X�g���N�^
AOtherPlayerController::AOtherPlayerController(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
	, MoveTarget(FVector::ZeroVector)
	, PrevPos(FVector::ZeroVector)
	, MoveTime(0.0f)
{
}


// Pawn���R�t����ꂽ�B
void AOtherPlayerController::OnPossess(APawn *aPawn)
{
	Super::OnPossess(aPawn);

	pCharacter = Cast<AOtherPlayerCharacter>(aPawn);
	check(pCharacter != nullptr);
}

// ���t���[���̏���.
void AOtherPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (MoveTime <= 0.0f) { return; }

	MoveTime -= DeltaTime;
	if (MoveTime <= 0.0f)
	{
		MoveTime = 0.0f;
		pCharacter->SetActorLocation(MoveTarget);
		return;
	}
	FVector Pos = FMath::Lerp<FVector>(PrevPos, MoveTarget, 1.0f- (MoveTime / MoveInterval));
	pCharacter->SetActorLocation(Pos);
}

// �ړ�.
void AOtherPlayerController::Move(float X, float Y, float Z, float Rotation)
{
	pCharacter->SetActorRotation(FRotator(0.0f, Rotation, 0.0f));
	PrevPos = pCharacter->GetActorLocation();
	MoveTarget = FVector(X, Y, Z);

	MoveTime = MoveInterval;
}

// �ړ��x�N�g���̎擾.
FVector AOtherPlayerController::GetMoveVector() const
{
	if (MoveTime <= 0.0f) { return FVector::ZeroVector; }
	return (MoveTarget - PrevPos).GetSafeNormal();
}
