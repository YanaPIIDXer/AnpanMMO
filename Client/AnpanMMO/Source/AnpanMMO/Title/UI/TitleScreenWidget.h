// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TitleScreenWidget.generated.h"

DECLARE_DELEGATE_OneParam(FOnConnect, bool);

/**
 * タイトル画面Widget
 */
UCLASS()
class ANPANMMO_API UTitleScreenWidget : public UUserWidget
{

	GENERATED_BODY()
	
public:

	// 生成.
	static UTitleScreenWidget *Show(UObject *pOuter);

	// コンストラクタ
	UTitleScreenWidget(const FObjectInitializer &ObjectInitializer);

	// デストラクタ
	virtual ~UTitleScreenWidget() {}


	// 接続コールバック
	FOnConnect OnConnect;

protected:

	// ゲームサーバへの接続.
	UFUNCTION(BlueprintCallable, Category = "Connection")
	void ConnectToGameServer();

private:

	// Widgetのパス
	static const TCHAR *WidgetPath;
	
};
