// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LayeredMenuWidgetBase.generated.h"

DECLARE_DELEGATE(FOnMenuClosed);

class MemoryStreamInterface;

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

	// 閉じる
	UFUNCTION(BlueprintCallable, Category = "Menu")
	void Close();

	// 子を閉じる。
	UFUNCTION(BlueprintCallable, Category = "Menu")
	void CloseChild();

	// パケットを受信した。
	virtual void OnRecvPacket(uint8 ID, MemoryStreamInterface *pStream) {}


	// メニューが閉じられた。
	FOnMenuClosed OnMenuClosed;

protected:

	// 戻る
	UFUNCTION(BlueprintCallable, Category = "Menu")
	void Back();

	// 戻ってきた時のイベント
	UFUNCTION(BlueprintNativeEvent, Category = "Menu")
	void OnBackFromChild();
	virtual void OnBackFromChild_Implementation() {}

	// 子を表示.
	UFUNCTION(BlueprintCallable, Category = "Menu")
	void ShowChild(ULayeredMenuWidgetBase *pInChildMenu, bool bHideSelf = true);

private:

	// 親メニュー
	UPROPERTY()
	ULayeredMenuWidgetBase *pParentMenu;

	// 子メニュー
	UPROPERTY()
	ULayeredMenuWidgetBase *pChildMenu;

	// ZOrder
	int32 ZOrder;

};
