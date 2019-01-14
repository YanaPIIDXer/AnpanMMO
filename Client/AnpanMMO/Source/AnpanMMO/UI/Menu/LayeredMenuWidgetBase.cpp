// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#include "LayeredMenuWidgetBase.h"
#include "Kismet/GameplayStatics.h"
#include "Active/ActiveGameMode.h"

// �R���X�g���N�^
ULayeredMenuWidgetBase::ULayeredMenuWidgetBase(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
	, pParentMenu(nullptr)
	, pChildMenu(nullptr)
	, ZOrder(0)
{
}

// �\��.
void ULayeredMenuWidgetBase::Show(int32 InZOrder)
{
	AActiveGameMode *pGameMode = Cast<AActiveGameMode>(UGameplayStatics::GetGameMode(this));
	check(pGameMode != nullptr);

	pGameMode->SetCurrentMenu(this);
	pGameMode->SetHiddenMainHUD(true);

	ZOrder = InZOrder;
	AddToViewport(ZOrder);
}

// ����
void ULayeredMenuWidgetBase::Close()
{
	RemoveFromParent();
	OnMenuClosed.ExecuteIfBound();

	// �q������B
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

// �q�����
void ULayeredMenuWidgetBase::CloseChild()
{
	if (pChildMenu == nullptr) { return; }
	
	pChildMenu->RemoveFromParent();
	pChildMenu = nullptr;
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

		pGameMode->SetCurrentMenu(nullptr);
		pGameMode->SetHiddenMainHUD(false);
	}
}

// �q��\��.
void ULayeredMenuWidgetBase::ShowChild(ULayeredMenuWidgetBase *pInChildMenu, bool bHideSelf)
{
	CloseChild();		// �q���ʂɊJ���Ă����ꍇ�͕���B

	if (bHideSelf)
	{
		SetVisibility(ESlateVisibility::Hidden);
	}
	pChildMenu = pInChildMenu;
	pChildMenu->pParentMenu = this;
	pChildMenu->Show(ZOrder + 1);
}
