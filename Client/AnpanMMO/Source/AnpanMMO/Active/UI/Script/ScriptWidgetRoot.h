// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/Menu/LayeredMenuWidgetBase.h"
#include "ScriptWidgetRoot.generated.h"

class UScriptMessageWidget;

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

	// Widgetを閉じる。
	void CloseWidget();

private:
	
	// メッセージWidget
	UPROPERTY()
	UScriptMessageWidget *pMessageWidget;

	// 現在表示中のWidget
	UPROPERTY()
	UUserWidget *pCurrentWidget;

};
