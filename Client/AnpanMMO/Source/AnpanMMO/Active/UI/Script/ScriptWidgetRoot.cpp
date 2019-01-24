// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#include "ScriptWidgetRoot.h"
#include "ScriptMessageWidget.h"
#include "ScriptSelectionWidget.h"
#include "ScriptShopWidget.h"

// コンストラクタ
UScriptWidgetRoot::UScriptWidgetRoot(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
	, pMessageWidget(nullptr)
	, pSelectionWidget(nullptr)
	, pCurrentWidget(nullptr)
{
}

// 初期化.
void UScriptWidgetRoot::Init()
{
	pMessageWidget = UScriptMessageWidget::Create(this);
	pSelectionWidget = UScriptSelectionWidget::Create(this);
	pShopWidget = UScriptShopWidget::Create(this);
}

// メッセージ表示.
void UScriptWidgetRoot::ShowMessage(const FString &Message)
{
	pMessageWidget->SetMessage(Message);
	if (pCurrentWidget != pMessageWidget)
	{
		pCurrentWidget = pMessageWidget;
		ShowChild(pMessageWidget);
	}
}

// 選択肢を追加.
void UScriptWidgetRoot::AddSelection(const FString &Item)
{
	pSelectionWidget->AddSelection(Item);
}

// 選択肢を表示.
void UScriptWidgetRoot::ShowSelection()
{
	pSelectionWidget->Init();
	if (pCurrentWidget != pSelectionWidget)
	{
		pCurrentWidget = pSelectionWidget;
		ShowChild(pSelectionWidget);
	}
}

// ショップを表示.
void UScriptWidgetRoot::ShowShop(uint32 ShopId)
{
	pShopWidget->SetShopId(ShopId);
	pCurrentWidget = pShopWidget;
	ShowChild(pShopWidget);
}

// Widgetを閉じる。
void UScriptWidgetRoot::CloseWidget()
{
	pCurrentWidget = nullptr;
	Close();
}
