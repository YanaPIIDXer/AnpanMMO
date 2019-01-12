// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#include "GameMenuWidget.h"
#include "Util.h"
#include "Kismet/GameplayStatics.h"
#include "MMOGameInstance.h"
#include "Active/ActiveGameMode.h"
#include "Active/UI/MainHUD.h"
#include "Party/PartyCreateMenuWidget.h"
#include "Party/PartyInfoMenuWidget.h"

const TCHAR *UGameMenuWidget::AssetPath = TEXT("/Game/Blueprints/UI/Active/Menu/GameMenu.GameMenu");

// 表示.
UGameMenuWidget *UGameMenuWidget::ShowWidget(UObject *pOuter)
{
	auto *pWidget = Util::LoadBlueprint<UGameMenuWidget>(pOuter, AssetPath);
	check(pWidget != nullptr);

	pWidget->Show(1);
	return pWidget;
}

// コンストラクタ
UGameMenuWidget::UGameMenuWidget(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
}


// パーティメニュー表示.
void UGameMenuWidget::ShowPartyMenu()
{
	AActiveGameMode *pGameMode = Cast<AActiveGameMode>(UGameplayStatics::GetGameMode(this));
	check(pGameMode != nullptr);

	if (!pGameMode->GetPartyInfo().IsJoined())
	{
		auto *pChild = UPartyCreateMenuWidget::Create(this);
		ShowChild(pChild);
	}
	else
	{
		auto *pChild = UPartyInfoMenuWidget::Create(this);
		ShowChild(pChild);
	}
}

// ログアウト
void UGameMenuWidget::LogOut()
{
	UMMOGameInstance *pInst = Cast<UMMOGameInstance>(UGameplayStatics::GetGameInstance(this));
	check(pInst != nullptr);

	pInst->Close();

	AActiveGameMode *pGameMode = Cast<AActiveGameMode>(UGameplayStatics::GetGameMode(this));
	check(pGameMode != nullptr);

	pGameMode->GetMainHUD()->OnLogOut();
}
