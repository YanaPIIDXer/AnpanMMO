// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/Menu/LayeredMenuWidgetBase.h"
#include "SkillMenu.generated.h"

/**
 * スキルメニュー
 */
UCLASS()
class ANPANMMO_API USkillMenu : public ULayeredMenuWidgetBase
{

	GENERATED_BODY()

public:

	// コンストラクタ
	USkillMenu(const FObjectInitializer &ObjectInitializer);

	// デストラクタ
	virtual ~USkillMenu() {}

	// パケットを受信した。
	virtual void OnRecvPacket(uint8 ID) override;

protected:

	// メニューの再初期化.
	UFUNCTION(BlueprintNativeEvent, Category = "SkillMenu")
	void RefleshMenu();
	void RefleshMenu_Implementation() {}

};
