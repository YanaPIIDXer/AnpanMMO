// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Controller.h"
#include "AnpanController.generated.h"

class AAnpan;

/**
 * �A���p���R���g���[���N���X
 */
UCLASS()
class ANPANMMO_API AAnpanController : public AController
{

	GENERATED_BODY()

public:

	// �R���X�g���N�^
	AAnpanController(const FObjectInitializer &ObjectInitializer);

	// �f�X�g���N�^
	virtual ~AAnpanController() {}

	// Pawn���R�t����ꂽ.
	virtual void Possess(APawn *aPawn) override;

private:
	
	// �A���p��.
	TWeakObjectPtr<AAnpan> pAnpan;

};
