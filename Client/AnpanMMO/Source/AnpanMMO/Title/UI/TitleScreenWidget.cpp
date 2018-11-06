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


// ゲームサーバへの接続.
void UTitleScreenWidget::ConnectToGameServer()
{
	UMMOGameInstance *pInst = Cast<UMMOGameInstance>(GetGameInstance());
	check(pInst != nullptr);

	if (!pInst->Connect(Config::ServerHost, Config::ServerPort))
	{
		OnConnect.ExecuteIfBound(false);
		return;
	}
	OnConnect.ExecuteIfBound(true);

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
