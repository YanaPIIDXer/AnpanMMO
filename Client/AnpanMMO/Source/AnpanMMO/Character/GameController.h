// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GameController.generated.h"

/**
 * �R���g���[���N���X
 */
UCLASS()
class ANPANMMO_API AGameController : public APlayerController
{

	GENERATED_BODY()
	
public:

	// �R���X�g���N�^
	AGameController(const FObjectInitializer &ObjectInitializer);
	
	// �f�X�g���N�^
	virtual ~AGameController() {}

private:
	
};
