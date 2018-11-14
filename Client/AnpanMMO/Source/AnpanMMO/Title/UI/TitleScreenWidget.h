// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MasterDownloader.h"
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

	// フェード開始.
	UFUNCTION(BlueprintNativeEvent, Category = "Fade")
	void StartFade();
	void StartFade_Implementation() {}


	// 接続コールバック
	FOnConnect OnConnect;

	// ゲーム画面に移行する準備が完了した時のコールバック
	FOnReadyToGame OnReadyToGame;
	
protected:

	// マスタダウンロード開始.
	UFUNCTION(BlueprintCallable, Category = "Master")
	void StartMasterDownload();

	// ダウンロードが完了した。
	UFUNCTION(BlueprintNativeEvent, Category = "Master")
	void OnMasterDownloaded(bool bSuccess);
	void OnMasterDownloaded_Implementation(bool bSuccess) {}

	// ゲームサーバへの接続.
	UFUNCTION(BlueprintCallable, Category = "Connection")
	void ConnectToGameServer();

	// フェードが完了した。
	UFUNCTION(BlueprintCallable, Category = "Fade")
	void OnFadeFinish();

private:

	// Widgetのパス
	static const TCHAR *WidgetPath;

	// マスタダウンローダ
	MasterDownloader MasterDownload;

};
