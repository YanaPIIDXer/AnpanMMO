// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "YesNoDialog.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDialogResult);

/**
 * はい・いいえのダイアログ
 */
UCLASS()
class ANPANMMO_API UYesNoDialog : public UUserWidget
{

	GENERATED_BODY()
	
public:

	// 表示.
	static UYesNoDialog *Show(UObject *pOuter, const FString &DisplayText, int32 ZOrder = 0);

	// コンストラクタ
	UYesNoDialog(const FObjectInitializer &ObjectInitializer);

	// デストラクタ
	virtual ~UYesNoDialog() {}


	// はいが選択された。
	UPROPERTY(BlueprintAssignable, Category = "Dialog")
	FOnDialogResult OnYes;

	// いいえが選択された。
	UPROPERTY(BlueprintAssignable, Category = "Dialog")
	FOnDialogResult OnNo;

protected:

	// はいが選択された。
	UFUNCTION(BlueprintCallable, Category = "Dialog")
	void OnSelectedYes();

	// いいえが選択された。
	UFUNCTION(BlueprintCallable, Category = "Dialog")
	void OnSelectedNo();


	// 表示文字列.
	UPROPERTY(BlueprintReadOnly, Category = "Dialog")
	FString DisplayText;

private:

	// アセットパス
	static const TCHAR *AssetPath;

};
