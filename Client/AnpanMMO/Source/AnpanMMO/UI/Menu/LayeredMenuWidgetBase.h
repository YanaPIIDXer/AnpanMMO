// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LayeredMenuWidgetBase.generated.h"

/**
 * レイヤに分割されたメニューWidget基底クラス
 */
UCLASS()
class ANPANMMO_API ULayeredMenuWidgetBase : public UUserWidget
{

	GENERATED_BODY()
	
public:

	// コンストラクタ
	ULayeredMenuWidgetBase(const FObjectInitializer &ObjectInitializer);

	// デストラクタ
	virtual ~ULayeredMenuWidgetBase() {}

	// 表示.
	void Show(int32 InZOrder = 0);

protected:

	// 戻る
	UFUNCTION(BlueprintCallable, Category = "Menu")
	void Back();

	// 閉じる
	UFUNCTION(BlueprintCallable, Category = "Menu")
	void Close();

	// 子を表示.
	UFUNCTION(BlueprintCallable, Category = "Menu")
	void ShowChild(ULayeredMenuWidgetBase *pChildMenu, bool bHideSelf = true);

private:

	// 親メニュー
	UPROPERTY()
	ULayeredMenuWidgetBase *pParentMenu;

	// ZOrder
	int32 ZOrder;

};
