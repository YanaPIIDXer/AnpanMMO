// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "CharacterBase.generated.h"

/**
 * �L�����N�^���N���X
 */
UCLASS()
class ANPANMMO_API ACharacterBase : public APawn
{
	GENERATED_BODY()

public:

	// �R���X�g���N�^
	ACharacterBase(const FObjectInitializer &ObjectInitializer);

	// �f�X�g���N�^
	virtual ~ACharacterBase() {}

protected:

private:
	
};
