// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "ScriptWidgetRoot.h"
#include "ScriptMessageWidget.h"

// コンストラクタ
UScriptWidgetRoot::UScriptWidgetRoot(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
	, pMessageWidget(nullptr)
	, pCurrentWidget(nullptr)
{
}

// スクリプト
void UScriptWidgetRoot::Init()
{
	pMessageWidget = UScriptMessageWidget::Create(this);
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
