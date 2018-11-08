// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Controller.h"
#include "AnpanController.generated.h"

class AAnpan;

/**
 * アンパンコントローラクラス
 */
UCLASS()
class ANPANMMO_API AAnpanController : public AController
{

	GENERATED_BODY()

public:

	// コンストラクタ
	AAnpanController(const FObjectInitializer &ObjectInitializer);

	// デストラクタ
	virtual ~AAnpanController() {}

	// Pawnが紐付けられた.
	virtual void Possess(APawn *aPawn) override;

private:
	
	// アンパン.
	TWeakObjectPtr<AAnpan> pAnpan;

};
