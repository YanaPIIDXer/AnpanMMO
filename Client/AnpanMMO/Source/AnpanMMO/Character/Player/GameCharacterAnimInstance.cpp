// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "GameCharacterAnimInstance.h"
#include "GameCharacter.h"
#include "GameFramework/PawnMovementComponent.h"

// コンストラクタ
UGameCharacterAnimInstance::UGameCharacterAnimInstance(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
	, MoveVector(FVector::ZeroVector)
	, pCharacter(nullptr)
	, pMovementComponent(nullptr)
{
}

// 開始時の処理.
void UGameCharacterAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	pCharacter = Cast<AGameCharacter>(TryGetPawnOwner());
	if (pCharacter != nullptr)
	{
		pMovementComponent = pCharacter->GetMovementComponent();
	}
}

// 毎フレームの処理.
void UGameCharacterAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	if (pCharacter == nullptr || pMovementComponent == nullptr) { return; }

	MoveVector = pMovementComponent->GetLastInputVector();
}
