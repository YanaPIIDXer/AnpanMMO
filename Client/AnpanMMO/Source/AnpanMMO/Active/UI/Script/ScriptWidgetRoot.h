// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/Menu/LayeredMenuWidgetBase.h"
#include "ScriptWidgetRoot.generated.h"

/**
 * スクリプトWidgetの親.
 */
UCLASS()
class ANPANMMO_API UScriptWidgetRoot : public ULayeredMenuWidgetBase
{

	GENERATED_BODY()

public:

	// コンストラクタ
	UScriptWidgetRoot(const FObjectInitializer &ObjectInitializer);

	// デストラクタ
	virtual ~UScriptWidgetRoot() {}

private:
	


};
