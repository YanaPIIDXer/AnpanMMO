// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "LayeredMenuWidgetBase.h"

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
	ZOrder = InZOrder;
	AddToViewport(ZOrder);
}


// �߂�
void ULayeredMenuWidgetBase::Back()
{
	RemoveFromParent();
	if (pParentMenu != nullptr)
	{
		pParentMenu->SetVisibility(ESlateVisibility::Visible);
	}
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
