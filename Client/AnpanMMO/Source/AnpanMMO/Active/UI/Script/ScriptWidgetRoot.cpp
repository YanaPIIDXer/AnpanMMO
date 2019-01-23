// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#include "ScriptWidgetRoot.h"
#include "ScriptMessageWidget.h"
#include "ScriptSelectionWidget.h"

// �R���X�g���N�^
UScriptWidgetRoot::UScriptWidgetRoot(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
	, pMessageWidget(nullptr)
	, pSelectionWidget(nullptr)
	, pCurrentWidget(nullptr)
{
}

// ������.
void UScriptWidgetRoot::Init()
{
	pMessageWidget = UScriptMessageWidget::Create(this);
	pSelectionWidget = UScriptSelectionWidget::Create(this);
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

// �I������ǉ�.
void UScriptWidgetRoot::AddSelection(const FString &Item)
{
	pSelectionWidget->AddSelection(Item);
}

// �I������\��.
void UScriptWidgetRoot::ShowSelection()
{
	pSelectionWidget->Init();
	if (pCurrentWidget != pSelectionWidget)
	{
		pCurrentWidget = pSelectionWidget;
		ShowChild(pSelectionWidget);
	}
}

// �V���b�v��\��.
void UScriptWidgetRoot::ShowShop(uint32 ShopId)
{

}

// Widget�����B
void UScriptWidgetRoot::CloseWidget()
{
	pCurrentWidget = nullptr;
	Close();
}
