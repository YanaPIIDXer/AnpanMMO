// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SkillTreeWidget.generated.h"

/**
 * スキルツリー画面.
 */
UCLASS()
class ANPANMMO_API USkillTreeWidget : public UUserWidget
{

	GENERATED_BODY()
	
public:

	// コンストラクタ
	USkillTreeWidget(const FObjectInitializer &ObjectInitializer);

	// デストラクタ
	virtual ~USkillTreeWidget() {}

	// 初期化.
	UFUNCTION(BlueprintCallable, Category = "SkillTree")
	void Init();

protected:

	// 初期化イベント
	UFUNCTION(BlueprintNativeEvent, Category = "SkillTree")
	void InitEvent();
	void InitEvent_Implementation() {}

};
