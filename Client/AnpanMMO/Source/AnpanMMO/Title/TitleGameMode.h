// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "TitleGameMode.generated.h"

/**
 * �^�C�g�����GameMode
 */
UCLASS()
class ANPANMMO_API ATitleGameMode : public AGameMode
{

	GENERATED_BODY()
	
public:

	// �R���X�g���N�^
	ATitleGameMode(const FObjectInitializer &ObjectInitializer);

	// �f�X�g���N�^
	virtual ~ATitleGameMode() {}

private:
	
	
};
