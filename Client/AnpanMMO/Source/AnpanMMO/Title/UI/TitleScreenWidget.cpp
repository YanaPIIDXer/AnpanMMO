// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "TitleScreenWidget.h"
#include "MMOGameInstance.h"
#include "Config.h"

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
	}
}
