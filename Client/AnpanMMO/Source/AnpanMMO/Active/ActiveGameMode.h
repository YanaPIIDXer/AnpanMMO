// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "ActiveGameMode.generated.h"

/**
 * ゲーム中GameMode
 */
UCLASS()
class ANPANMMO_API AActiveGameMode : public AGameMode
{
	GENERATED_BODY()

public:

	// コンストラクタ
	AActiveGameMode(const FObjectInitializer &ObjectInitializer);

	// デストラクタ
	virtual ~AActiveGameMode() {}

protected:

private:
	
};
