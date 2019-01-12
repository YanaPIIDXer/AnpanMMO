// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/Menu/LayeredMenuWidgetBase.h"
#include "ScriptWidgetRoot.generated.h"

class UScriptMessageWidget;
class UScriptSelectionWidget;

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

	// 初期化.
	// ※Initializeと言う関数名にしたかったが既に使われているようだ。
	void Init();

	// メッセージ表示.
	void ShowMessage(const FString &Message);

	// 選択肢を追加.
	void AddSelection(const FString &Item);

	// 選択肢を表示.
	void ShowSelection();

	// Widgetを閉じる。
	void CloseWidget();

private:
	
	// メッセージWidget
	UPROPERTY()
	UScriptMessageWidget *pMessageWidget;

	// 選択肢Widget
	UPROPERTY()
	UScriptSelectionWidget *pSelectionWidget;

	// 現在表示中のWidget
	UPROPERTY()
	UUserWidget *pCurrentWidget;

};
