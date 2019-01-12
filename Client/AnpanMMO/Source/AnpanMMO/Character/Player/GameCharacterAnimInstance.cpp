// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#include "GameCharacterAnimInstance.h"
#include "PlayerCharacterBase.h"
#include "GameFramework/PawnMovementComponent.h"

// �R���X�g���N�^
UGameCharacterAnimInstance::UGameCharacterAnimInstance(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
	, MoveVector(FVector::ZeroVector)
	, pCharacter(nullptr)
{
}

// �J�n���̏���.
void UGameCharacterAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	pCharacter = Cast<APlayerCharacterBase>(TryGetPawnOwner());
}

// ���t���[���̏���.
void UGameCharacterAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	if (pCharacter == nullptr) { return; }

	MoveVector = pCharacter->GetMoveVector();
}
