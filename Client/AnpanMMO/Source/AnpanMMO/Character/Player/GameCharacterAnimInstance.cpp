// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "GameCharacterAnimInstance.h"
#include "GameCharacter.h"
#include "GameFramework/PawnMovementComponent.h"

// �R���X�g���N�^
UGameCharacterAnimInstance::UGameCharacterAnimInstance(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
	, MoveVector(FVector::ZeroVector)
	, pCharacter(nullptr)
	, pMovementComponent(nullptr)
{
}

// �J�n���̏���.
void UGameCharacterAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	pCharacter = Cast<AGameCharacter>(TryGetPawnOwner());
	if (pCharacter != nullptr)
	{
		pMovementComponent = pCharacter->GetMovementComponent();
	}
}

// ���t���[���̏���.
void UGameCharacterAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	if (pCharacter == nullptr || pMovementComponent == nullptr) { return; }

	MoveVector = pMovementComponent->GetLastInputVector();
}
