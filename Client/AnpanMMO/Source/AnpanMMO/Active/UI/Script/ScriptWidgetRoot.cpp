// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "ScriptWidgetRoot.h"
#include "ScriptMessageWidget.h"

// �R���X�g���N�^
UScriptWidgetRoot::UScriptWidgetRoot(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
	, pMessageWidget(nullptr)
	, pCurrentWidget(nullptr)
{
}

// �X�N���v�g
void UScriptWidgetRoot::Init()
{
	pMessageWidget = UScriptMessageWidget::Create(this);
}

// ���b�Z�[�W�\��.
void UScriptWidgetRoot::ShowMessage(const FString &Message)
{
	pMessageWidget->SetMessage(Message);
	if (pCurrentWidget != pMessageWidget)
	{
		pCurrentWidget = pMessageWidget;
		ShowChild(pMessageWidget);
	}
}
