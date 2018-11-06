// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "JoyStick.generated.h"

/**
 * ジョイスティック
 */
UCLASS()
class ANPANMMO_API UJoyStick : public UUserWidget
{

	GENERATED_BODY()
	
public:

	// コンストラクタ
	UJoyStick(const FObjectInitializer &ObjectInitializer);

	// デストラクタ
	virtual ~UJoyStick() {}

protected:


private:
	
	
};
