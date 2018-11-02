// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "TitleScreenWidget.h"
#include "MMOGameInstance.h"
#include "Config.h"
#include "Packet/PacketLogInRequest.h"
#include "IdManager.h"

const TCHAR *UTitleScreenWidget::WidgetPath = TEXT("/Game/Blueprints/UI/Title/TitleScreen.TitleScreen_C");

// 生成.
UTitleScreenWidget *UTitleScreenWidget::Create(UObject *pOuter)
{
	UBlueprintGeneratedClass *pClass = LoadObject<UBlueprintGeneratedClass>(pOuter, WidgetPath, WidgetPath);
	check(pClass != nullptr);

	UTitleScreenWidget *pWidget = NewObject<UTitleScreenWidget>(pOuter, pClass);
	check(pWidget != nullptr);

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
		UE_LOG(LogTemp, Log, TEXT("GameServer Connection Failed..."));
		return;
	}

	// ログインパケット送信.
	std::string FilePath = TCHAR_TO_UTF8(*Config::IdFilePath);
	IdManager IdMgr(FilePath);
	std::string Id = IdMgr.GetId();
	PacketLogInRequest Packet(Id);
	pInst->SendPacket(&Packet);
}
