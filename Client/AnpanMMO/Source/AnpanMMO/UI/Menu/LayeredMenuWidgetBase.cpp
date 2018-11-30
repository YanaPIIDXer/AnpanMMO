// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "LayeredMenuWidgetBase.h"
#include "Kismet/GameplayStatics.h"
#include "Active/ActiveGameMode.h"

// �R���X�g���N�^
ULayeredMenuWidgetBase::ULayeredMenuWidgetBase(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
	, pParentMenu(nullptr)
	, ZOrder(0)
{
}

// �\��.
void ULayeredMenuWidgetBase::Show(int32 InZOrder)
{
	AActiveGameMode *pGameMode = Cast<AActiveGameMode>(UGameplayStatics::GetGameMode(this));
	check(pGameMode != nullptr);

	pGameMode->SetHiddenMainHUD(true);

	ZOrder = InZOrder;
	AddToViewport(ZOrder);
}

// ����
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


// �߂�
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

// �q��\��.
void ULayeredMenuWidgetBase::ShowChild(ULayeredMenuWidgetBase *pChildMenu, bool bHideSelf)
{
	if (bHideSelf)
	{
		SetVisibility(ESlateVisibility::Hidden);
	}
	pChildMenu->pParentMenu = this;
	pChildMenu->Show(ZOrder + 1);
}
