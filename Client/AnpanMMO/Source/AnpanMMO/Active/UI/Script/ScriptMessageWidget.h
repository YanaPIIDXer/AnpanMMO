// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/Menu/LayeredMenuWidgetBase.h"
#include "ScriptMessageWidget.generated.h"

/**
 * スクリプト：メッセージウィンドウ
 */
UCLASS()
class ANPANMMO_API UScriptMessageWidget : public ULayeredMenuWidgetBase
{

	GENERATED_BODY()

public:

	// 生成.
	static UScriptMessageWidget *Create(UObject *pOuter);

	// コンストラクタ
	UScriptMessageWidget(const FObjectInitializer &ObjectInitializer);
	
	// デストラクタ
	virtual ~UScriptMessageWidget() {}

	// メッセージをセット。
	void SetMessage(const FString &InMessage) { Message = InMessage; }

protected:

	// メッセージ
	UPROPERTY(BlueprintReadonly, Category = "Script")
	FString Message;

private:

	// アセットパス
	static const TCHAR *AssetPath;


	// 次へ進む。
	UFUNCTION(BlueprintCallable, Category = "Script")
	void ToNext();
	
};
