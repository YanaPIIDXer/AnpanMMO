// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TitleScreenWidget.generated.h"

DECLARE_DELEGATE_OneParam(FOnConnect, bool);
DECLARE_DELEGATE(FOnReadyToGame);

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

	// ゲーム画面に移行する準備が完了した時のコールバック
	FOnReadyToGame OnReadyToGame;
	
protected:

	// ゲームサーバへの接続.
	UFUNCTION(BlueprintCallable, Category = "Connection")
	void ConnectToGameServer();

	// フェードが完了した。
	UFUNCTION(BlueprintCallable, Category = "Fade")
	void OnFadeFinish();

private:

	// Widgetのパス
	static const TCHAR *WidgetPath;
	
};
