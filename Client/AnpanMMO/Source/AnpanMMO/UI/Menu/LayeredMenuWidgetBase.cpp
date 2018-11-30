// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "LayeredMenuWidgetBase.h"
#include "Kismet/GameplayStatics.h"
#include "Active/ActiveGameMode.h"

// コンストラクタ
ULayeredMenuWidgetBase::ULayeredMenuWidgetBase(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
	, pParentMenu(nullptr)
	, ZOrder(0)
{
}

// 表示.
void ULayeredMenuWidgetBase::Show(int32 InZOrder)
{
	AActiveGameMode *pGameMode = Cast<AActiveGameMode>(UGameplayStatics::GetGameMode(this));
	check(pGameMode != nullptr);

	pGameMode->SetHiddenMainHUD(true);

	ZOrder = InZOrder;
	AddToViewport(ZOrder);
}

// 閉じる
void ULayeredMenuWidgetBase::Close()
{
	RemoveFromParent();
	OnMenuClosed.ExecuteIfBound();

	if (pParentMenu != nullptr)
	{
		pParentMenu->Close();
	}
	else
	{
		AActiveGameMode *pGameMode = Cast<AActiveGameMode>(UGameplayStatics::GetGameMode(this));
		check(pGameMode != nullptr);

		pGameMode->SetHiddenMainHUD(false);
	}
}


// 戻る
void ULayeredMenuWidgetBase::Back()
{
	RemoveFromParent();
	if (pParentMenu != nullptr)
	{
		pParentMenu->SetVisibility(ESlateVisibility::Visible);
		pParentMenu->OnBackFromChild();
	}
	else
	{
		AActiveGameMode *pGameMode = Cast<AActiveGameMode>(UGameplayStatics::GetGameMode(this));
		check(pGameMode != nullptr);

		pGameMode->SetHiddenMainHUD(false);
	}
}

// 子を表示.
void ULayeredMenuWidgetBase::ShowChild(ULayeredMenuWidgetBase *pChildMenu, bool bHideSelf)
{
	if (bHideSelf)
	{
		SetVisibility(ESlateVisibility::Hidden);
	}
	pChildMenu->pParentMenu = this;
	pChildMenu->Show(ZOrder + 1);
}
