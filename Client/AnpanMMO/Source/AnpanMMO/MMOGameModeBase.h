// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MMOGameModeBase.generated.h"

/**
 * GameMode���N���X
 */
UCLASS()
class ANPANMMO_API AMMOGameModeBase : public AGameModeBase
{

	GENERATED_BODY()
	
public:

	// �R���X�g���N�^
	AMMOGameModeBase(const FObjectInitializer &ObjectInitializer);

	// �f�X�g���N�^
	virtual ~AMMOGameModeBase() {}
	
protected:

private:
	
};
