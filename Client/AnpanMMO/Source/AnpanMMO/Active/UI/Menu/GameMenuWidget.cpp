// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "GameMenuWidget.h"
#include "Util.h"

const TCHAR *UGameMenuWidget::AssetPath = TEXT("/Game/Blueprints/UI/Active/Menu/GameMenu.GameMenu");
const int UGameMenuWidget::ZOrder = 1;

// 表示.
UGameMenuWidget *UGameMenuWidget::Show(UObject *pOuter)
{
	auto *pWidget = Util::LoadBlueprint<UGameMenuWidget>(pOuter, AssetPath);
	check(pWidget != nullptr);

	pWidget->AddToViewport(ZOrder);
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
	UE_LOG(LogTemp, Log, TEXT("Show Party Menu"));
}

// メニューを閉じる
void UGameMenuWidget::CloseMenu()
{
	RemoveFromParent();
}
