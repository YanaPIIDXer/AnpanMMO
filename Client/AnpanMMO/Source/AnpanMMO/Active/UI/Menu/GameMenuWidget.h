// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameMenuWidget.generated.h"

/**
 * ゲームメニューWidget
 */
UCLASS()
class ANPANMMO_API UGameMenuWidget : public UUserWidget
{

	GENERATED_BODY()

public:

	// 表示.
	static UGameMenuWidget *Show(UObject *pOuter);

	// コンストラクタ
	UGameMenuWidget(const FObjectInitializer &ObjectInitializer);

	// デストラクタ
	virtual ~UGameMenuWidget() {}

protected:

	// パーティメニュー表示.
	UFUNCTION(BlueprintCallable, Category = "Menu")
	void ShowPartyMenu();

	// メニューを閉じる
	UFUNCTION(BlueprintCallable, Category = "Menu")
	void CloseMenu();

private:

	// アセットのパス
	static const TCHAR *AssetPath;

	// ZOrder
	static const int32 ZOrder;
	
};
