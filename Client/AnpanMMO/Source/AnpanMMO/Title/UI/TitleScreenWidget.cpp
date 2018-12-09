// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "TitleScreenWidget.h"
#include "Config.h"
#include "MMOGameInstance.h"
#include "Title/TitleGameMode.h"
#include "Util.h"
#include "Kismet/GameplayStatics.h"

const TCHAR *UTitleScreenWidget::WidgetPath = TEXT("/Game/Blueprints/UI/Title/TitleScreen.TitleScreen");

// ����.
UTitleScreenWidget *UTitleScreenWidget::Show(UObject *pOuter)
{
	UTitleScreenWidget *pWidget = Util::LoadBlueprint<UTitleScreenWidget>(pOuter, WidgetPath);
	check(pWidget != nullptr);

	pWidget->AddToViewport();
	return pWidget;
}

// �R���X�g���N�^
UTitleScreenWidget::UTitleScreenWidget(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
}


// �}�X�^�_�E�����[�h�J�n.
void UTitleScreenWidget::StartMasterDownload()
{
	VersionDownload.DownloadResult.BindUObject<UTitleScreenWidget>(this, &UTitleScreenWidget::OnMasterDownloaded);
	if (!VersionDownload.Start(Config::MasterURL, Config::GetMasterDirectory()))
	{
		OnMasterDownloaded(false);
	}
}

// �X�N���v�g�_�E�����[�h�J�n.
void UTitleScreenWidget::StartScriptDownload()
{
	VersionDownload.DownloadResult.BindUObject<UTitleScreenWidget>(this, &UTitleScreenWidget::OnScriptDownloaded);
	if (!VersionDownload.Start(Config::ScriptURL, Config::GetScriptDirectory()))
	{
		OnScriptDownloaded(false);
	}
}

// DLC�_�E�����[�h�J�n.
void UTitleScreenWidget::StartDLCDownload()
{
#if !WITH_EDITOR
	VersionDownload.DownloadResult.BindUObject<UTitleScreenWidget>(this, &UTitleScreenWidget::OnDLCDownloaded);
	if (!VersionDownload.Start(Config::DLCURL, Config::GetDLCDirectory()))
	{
		OnDLCDownloaded(false);
	}
#else
	// Editor��ł͖ⓚ���p�Ő��������Ƃ���B
	OnDLCDownloaded(true);
#endif
}

// �Q�[���T�[�o�ւ̐ڑ�.
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

	// ���O�C���p�P�b�g���M.
	ATitleGameMode *pGameMode = Cast<ATitleGameMode>(UGameplayStatics::GetGameMode(this));
	check(pGameMode != nullptr);
	pGameMode->SendLogInRequest();
}

// �t�F�[�h�����������B
void UTitleScreenWidget::OnFadeFinish()
{
	OnReadyToGame.ExecuteIfBound();
}
