// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/Menu/LayeredMenuWidgetBase.h"
#include "ScriptShopWidget.generated.h"

/**
 * スクリプト：ショップ画面.
 */
UCLASS()
class ANPANMMO_API UScriptShopWidget : public ULayeredMenuWidgetBase
{

	GENERATED_BODY()
	
public:

	// 生成.
	static UScriptShopWidget *Create(UObject *pOuter);

	// コンストラクタ
	UScriptShopWidget(const FObjectInitializer &ObjectInitializer);

	// デストラクタ
	virtual ~UScriptShopWidget() {}

	// 初期化.
	void Init(uint32 InShopId);

protected:

	// 次へ進む。
	UFUNCTION(BlueprintCallable, Category = "Shop")
	void ToNext();

private:

	// アセットのパス
	static const TCHAR *AssetPath;

	// ショップＩＤ
	uint32 ShopId;

};
