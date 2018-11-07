// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Controller.h"
#include "OtherPlayerController.generated.h"

/**
 * 他人のコントローラ
 */
UCLASS()
class ANPANMMO_API AOtherPlayerController : public AController
{

	GENERATED_BODY()
	
public:

	// コンストラクタ
	AOtherPlayerController(const FObjectInitializer &ObjectInitializer);

	// デストラクタ
	virtual ~AOtherPlayerController() {}

private:
	
	
};
