// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MMOGameModeBase.generated.h"

/**
 * GameMode基底クラス
 */
UCLASS()
class ANPANMMO_API AMMOGameModeBase : public AGameModeBase
{

	GENERATED_BODY()
	
public:

	// コンストラクタ
	AMMOGameModeBase(const FObjectInitializer &ObjectInitializer);

	// デストラクタ
	virtual ~AMMOGameModeBase() {}
	
protected:

private:
	
};
