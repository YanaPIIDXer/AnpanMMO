// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MMOGameModeBase.h"
#include "ActiveGameMode.generated.h"

/**
 * �Q�[����GameMode
 */
UCLASS()
class ANPANMMO_API AActiveGameMode : public AMMOGameModeBase
{

	GENERATED_BODY()

public:

	// �R���X�g���N�^
	AActiveGameMode(const FObjectInitializer &ObjectInitializer);

	// �f�X�g���N�^
	virtual ~AActiveGameMode() {}

protected:

private:

};
