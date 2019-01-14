// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#include "LayeredMenuWidgetBase.h"
#include "Kismet/GameplayStatics.h"
#include "Active/ActiveGameMode.h"

// コンストラクタ
ULayeredMenuWidgetBase::ULayeredMenuWidgetBase(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
	, pParentMenu(nullptr)
	, pChildMenu(nullptr)
	, ZOrder(0)
{
}

// 表示.
void ULayeredMenuWidgetBase::Show(int32 InZOrder)
{
	AActiveGameMode *pGameMode = Cast<AActiveGameMode>(UGameplayStatics::GetGameMode(this));
	check(pGameMode != nullptr);

	pGameMode->SetCurrentMenu(this);
	pGameMode->SetHiddenMainHUD(true);

	ZOrder = InZOrder;
	AddToViewport(ZOrder);
}

// 閉じる
void ULayeredMenuWidgetBase::Close()
{
	RemoveFromParent();
	OnMenuClosed.ExecuteIfBound();

	// 子も閉じる。
	CloseChild();

	if (pParentMenu != nullptr)
	{
		pParentMenu->Close();
	}
	else
	{
		AActiveGameMode *pGameMode = Cast<AActiveGameMode>(UGameplayStatics::GetGameMode(this));
		check(pGameMode != nullptr);

		pGameMode->SetCurrentMenu(nullptr);
		pGameMode->SetHiddenMainHUD(false);
	}
}

// 子を閉じる
void ULayeredMenuWidgetBase::CloseChild()
{
	if (pChildMenu == nullptr) { return; }
	
	pChildMenu->RemoveFromParent();
	pChildMenu = nullptr;
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

		pGameMode->SetCurrentMenu(nullptr);
		pGameMode->SetHiddenMainHUD(false);
	}
}

// 子を表示.
void ULayeredMenuWidgetBase::ShowChild(ULayeredMenuWidgetBase *pInChildMenu, bool bHideSelf)
{
	CloseChild();		// 子が別に開いていた場合は閉じる。

	if (bHideSelf)
	{
		SetVisibility(ESlateVisibility::Hidden);
	}
	pChildMenu = pInChildMenu;
	pChildMenu->pParentMenu = this;
	pChildMenu->Show(ZOrder + 1);
}
