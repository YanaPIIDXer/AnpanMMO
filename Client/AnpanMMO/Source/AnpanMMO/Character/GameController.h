// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GameCamera.h"
#include "GameController.generated.h"

/**
 * コントローラクラス
 */
UCLASS()
class ANPANMMO_API AGameController : public APlayerController
{

	GENERATED_BODY()
	
public:

	// コンストラクタ
	AGameController(const FObjectInitializer &ObjectInitializer);
	
	// デストラクタ
	virtual ~AGameController() {}

	// Pawnが紐付けられた。
	virtual void Possess(APawn *aPawn) override;

private:
	
	// カメラ
	TWeakObjectPtr<AGameCamera> pCamera;

};
