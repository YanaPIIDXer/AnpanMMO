// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SkillMenu.h"
#include "Blueprint/UserWidget.h"
#include "SkillListWidget.generated.h"

/**
 * スキルリスト画面.
 */
UCLASS()
class ANPANMMO_API USkillListWidget : public UUserWidget
{

	GENERATED_BODY()

public:

	// コンストラクタ
	USkillListWidget(const FObjectInitializer &ObjectInitializer);

	// デストラクタ
	virtual ~USkillListWidget() {}

	// 初期化.
	UFUNCTION(BlueprintCallable, Category = "SkillList")
	void Init();

protected:

	// 初期化イベント
	UFUNCTION(BlueprintNativeEvent, Category = "SkillList")
	void InitEvent();
	void InitEvent_Implementation() {}
	
};
