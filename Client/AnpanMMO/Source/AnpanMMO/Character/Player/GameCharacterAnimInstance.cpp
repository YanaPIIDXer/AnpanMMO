// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#include "GameCharacterAnimInstance.h"
#include "PlayerCharacterBase.h"
#include "GameFramework/PawnMovementComponent.h"

// コンストラクタ
UGameCharacterAnimInstance::UGameCharacterAnimInstance(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
	, MoveVector(FVector::ZeroVector)
	, pCharacter(nullptr)
{
}

// 開始時の処理.
void UGameCharacterAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	pCharacter = Cast<APlayerCharacterBase>(TryGetPawnOwner());
}

// 毎フレームの処理.
void UGameCharacterAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	if (pCharacter == nullptr) { return; }

	MoveVector = pCharacter->GetMoveVector();
}
