// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SimpleDialog.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDialogOK);

/**
 * 単純なダイアログ
 */
UCLASS()
class ANPANMMO_API USimpleDialog : public UUserWidget
{

	GENERATED_BODY()
	
public:

	// 表示.
	static USimpleDialog *Show(UObject *pOuter, const FString &InDisplayText, int32 ZOrder = 0);

	// コンストラクタ
	USimpleDialog(const FObjectInitializer &ObjectInitializer);

	// デストラクタ
	virtual ~USimpleDialog() {}

	// OKボタンが押された。
	UPROPERTY(BlueprintAssignable, Category = "Dialog")
	FOnDialogOK OnDialogOK;

protected:

	// OKボタンが押された。
	UFUNCTION(BlueprintCallable, Category = "Dialog")
	void OnOK();

	// 表示文字列.
	UPROPERTY(BlueprintReadOnly, Category = "Dialog")
	FString DisplayText;
	
private:

	// Blueprintのパス.
	static const TCHAR *BlueprintPath;

};
