// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "GameCharacterAnimInstance.generated.h"

/**
 * GameCharacter用AnimInstance
 */
UCLASS()
class ANPANMMO_API UGameCharacterAnimInstance : public UAnimInstance
{

	GENERATED_BODY()
	
public:

	// コンストラクタ
	UGameCharacterAnimInstance(const FObjectInitializer &ObjectInitializer);

	// デストラクタ
	virtual ~UGameCharacterAnimInstance() {}

protected:

private:
	
};
