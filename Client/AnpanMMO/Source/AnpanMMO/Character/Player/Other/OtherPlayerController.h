// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Controller.h"
#include "OtherPlayerController.generated.h"

/**
 * ���l�̃R���g���[��
 */
UCLASS()
class ANPANMMO_API AOtherPlayerController : public AController
{

	GENERATED_BODY()
	
public:

	// �R���X�g���N�^
	AOtherPlayerController(const FObjectInitializer &ObjectInitializer);

	// �f�X�g���N�^
	virtual ~AOtherPlayerController() {}

private:
	
	
};
