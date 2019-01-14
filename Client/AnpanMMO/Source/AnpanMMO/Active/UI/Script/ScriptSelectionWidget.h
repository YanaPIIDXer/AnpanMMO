// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/Menu/LayeredMenuWidgetBase.h"
#include "ScriptSelectionWidget.generated.h"

/**
 * スクリプト：選択肢Widget
 */
UCLASS()
class ANPANMMO_API UScriptSelectionWidget : public ULayeredMenuWidgetBase
{

	GENERATED_BODY()

public:

	// 生成.
	static UScriptSelectionWidget *Create(UObject *pOuter);

	// コンストラクタ
	UScriptSelectionWidget(const FObjectInitializer &ObjectInitializer);

	// デストラクタ
	virtual ~UScriptSelectionWidget() {}

	// 初期化.
	void Init();

	// 選択肢を追加.
	void AddSelection(const FString &Item);

protected:

	// 選択.
	UFUNCTION(BlueprintCallable, Category = "Script")
	void Select(int32 Index);

	// 初期化イベント.
	UFUNCTION(BlueprintNativeEvent, Category = "Script")
	void InitEvent(const TArray<FString> &Items);
	void InitEvent_Implementation(const TArray<FString> &Items) {}

private:
	
	// アセットパス
	static const TCHAR *AssetPath;

	// 選択肢.
	TArray<FString> Selections;

};
