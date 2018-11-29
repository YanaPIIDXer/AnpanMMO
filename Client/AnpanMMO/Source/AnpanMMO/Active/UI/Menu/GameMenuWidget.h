// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/Menu/LayeredMenuWidgetBase.h"
#include "GameMenuWidget.generated.h"

/**
 * ゲームメニューWidget
 */
UCLASS()
class ANPANMMO_API UGameMenuWidget : public ULayeredMenuWidgetBase
{

	GENERATED_BODY()

public:

	// 表示.
	static UGameMenuWidget *ShowWidget(UObject *pOuter);

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

};
