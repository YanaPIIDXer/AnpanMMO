// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/Menu/LayeredMenuWidgetBase.h"
#include "EquipMenu.generated.h"

/**
 * 装備メニュー
 */
UCLASS()
class ANPANMMO_API UEquipMenu : public ULayeredMenuWidgetBase
{

	GENERATED_BODY()

public:

	// コンストラクタ
	UEquipMenu(const FObjectInitializer &ObjectInitializer);

	// デストラクタ
	virtual ~UEquipMenu() {}

protected:

};
