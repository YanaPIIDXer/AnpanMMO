// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "GameCharacterAnimInstance.generated.h"

class APlayerCharacterBase;

/**
 * GameCharacter�pAnimInstance
 */
UCLASS()
class ANPANMMO_API UGameCharacterAnimInstance : public UAnimInstance
{

	GENERATED_BODY()
	
public:

	// �R���X�g���N�^
	UGameCharacterAnimInstance(const FObjectInitializer &ObjectInitializer);

	// �f�X�g���N�^
	virtual ~UGameCharacterAnimInstance() {}

	// �J�n���̏���.
	virtual void NativeInitializeAnimation() override;

	// ���t���[���̏���.
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

protected:

	// �ړ��x�N�g��
	UPROPERTY(BlueprintReadOnly, Category = "Movement")
	FVector MoveVector;

private:

	// �L�����N�^�[
	TWeakObjectPtr<APlayerCharacterBase> pCharacter;

};
