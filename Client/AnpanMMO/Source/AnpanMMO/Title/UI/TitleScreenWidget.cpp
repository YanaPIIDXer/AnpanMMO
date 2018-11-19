// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "TitleScreenWidget.h"
#include "MMOGameInstance.h"
#include "Config.h"
#include "Packet/PacketLogInRequest.h"
#include "IdManager.h"
#include "Util.h"

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
	std::string FilePath = TCHAR_TO_UTF8(*Config::GetIdFilePath());
	IdManager IdMgr(FilePath);
	std::string Id = IdMgr.GetId();
	PacketLogInRequest Packet(Id);
	pInst->SendPacket(&Packet);
}

// フェードが完了した。
void UTitleScreenWidget::OnFadeFinish()
{
	OnReadyToGame.ExecuteIfBound();
}
