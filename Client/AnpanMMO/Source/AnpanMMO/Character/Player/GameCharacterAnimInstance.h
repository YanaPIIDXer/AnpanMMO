// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "GameCharacterAnimInstance.generated.h"

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

protected:

private:
	
};
