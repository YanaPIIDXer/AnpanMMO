// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "TitleScreenWidget.h"
#include "Config.h"
#include "MMOGameInstance.h"
#include "Title/TitleGameMode.h"
#include "Util.h"
#include "Kismet/GameplayStatics.h"

const TCHAR *UTitleScreenWidget::WidgetPath = TEXT("/Game/Blueprints/UI/Title/TitleScreen.TitleScreen");

// 生成.
UTitleScreenWidget *UTitleScreenWidget::Show(UObject *pOuter)
{
	UTitleScreenWidget *pWidget = Util::LoadBlueprint<UTitleScreenWidget>(pOuter, WidgetPath);
	check(pWidget != nullptr);

	pWidget->AddToViewport();
	return pWidget;
}

// コンストラクタ
UTitleScreenWidget::UTitleScreenWidget(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
}


// マスタダウンロード開始.
void UTitleScreenWidget::StartMasterDownload()
{
	VersionDownload.DownloadResult.BindUObject<UTitleScreenWidget>(this, &UTitleScreenWidget::OnMasterDownloaded);
	if (!VersionDownload.Start(Config::MasterURL, Config::GetMasterDirectory()))
	{
		OnMasterDownloaded(false);
	}
}

// スクリプトダウンロード開始.
void UTitleScreenWidget::StartScriptDownload()
{
	VersionDownload.DownloadResult.BindUObject<UTitleScreenWidget>(this, &UTitleScreenWidget::OnScriptDownloaded);
	if (!VersionDownload.Start(Config::ScriptURL, Config::GetScriptDirectory()))
	{
		OnScriptDownloaded(false);
	}
}

// DLCダウンロード開始.
void UTitleScreenWidget::StartDLCDownload()
{
#if !WITH_EDITOR
	VersionDownload.DownloadResult.BindUObject<UTitleScreenWidget>(this, &UTitleScreenWidget::OnDLCDownloaded);
	if (!VersionDownload.Start(Config::DLCURL, Config::GetDLCDirectory()))
	{
		OnDLCDownloaded(false);
	}
#else
	// Editor上では問答無用で成功扱いとする。
	OnDLCDownloaded(true);
#endif
}

// ゲームサーバへの接続.
void UTitleScreenWidget::ConnectToGameServer()
{
	UMMOGameInstance *pInst = Cast<UMMOGameInstance>(GetGameInstance());
	check(pInst != nullptr);

	if (!pInst->Connect(Config::ServerHost, Config::ServerPort))
	{
		OnConnect.ExecuteIfBound(false);
		OnConnectedGameServer(false);
		return;
	}
	OnConnect.ExecuteIfBound(true);
	OnConnectedGameServer(true);

	// ログインパケット送信.
	ATitleGameMode *pGameMode = Cast<ATitleGameMode>(UGameplayStatics::GetGameMode(this));
	check(pGameMode != nullptr);
	pGameMode->SendLogInRequest();
}

// フェードが完了した。
void UTitleScreenWidget::OnFadeFinish()
{
	OnReadyToGame.ExecuteIfBound();
}
