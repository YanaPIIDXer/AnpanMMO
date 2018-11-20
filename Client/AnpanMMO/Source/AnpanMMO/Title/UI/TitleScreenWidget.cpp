// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "TitleScreenWidget.h"
#include "MMOGameInstance.h"
#include "Config.h"
#include "Packet/PacketLogInRequest.h"
#include "IdManager.h"
#include "Util.h"

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
	std::string FilePath = TCHAR_TO_UTF8(*Config::GetIdFilePath());
	IdManager IdMgr(FilePath);
	std::string Id = IdMgr.GetId();
	PacketLogInRequest Packet(Id);
	pInst->SendPacket(&Packet);
}

// �t�F�[�h�����������B
void UTitleScreenWidget::OnFadeFinish()
{
	OnReadyToGame.ExecuteIfBound();
}
