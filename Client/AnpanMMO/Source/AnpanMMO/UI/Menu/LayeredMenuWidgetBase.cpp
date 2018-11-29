// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "LayeredMenuWidgetBase.h"

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
	ZOrder = InZOrder;
	AddToViewport(ZOrder);
}


// 戻る
void ULayeredMenuWidgetBase::Back()
{
	RemoveFromParent();
	if (pParentMenu != nullptr)
	{
		pParentMenu->SetVisibility(ESlateVisibility::Visible);
	}
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
