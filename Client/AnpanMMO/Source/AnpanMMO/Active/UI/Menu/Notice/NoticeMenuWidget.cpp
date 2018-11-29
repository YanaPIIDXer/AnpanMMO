// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "NoticeMenuWidget.h"
#include "Util.h"

const TCHAR *UNoticeMenuWidget::AssetPath = TEXT("/Game/Blueprints/UI/Active/Menu/Notice/NoticeMenu.NoticeMenu");

// �\��.
void UNoticeMenuWidget::ShowWidget(UObject *pOuter)
{
	UNoticeMenuWidget *pWidget = Util::LoadBlueprint<UNoticeMenuWidget>(pOuter, AssetPath);
	check(pWidget != nullptr);

	pWidget->Show();
}

// �R���X�g���N�^
UNoticeMenuWidget::UNoticeMenuWidget(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// �J�n���̏���.
void UNoticeMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();


}

// ============ UNoticeBase ===============

// �R���X�g���N�^
UNoticeBase::UNoticeBase(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// ========== UPartyInviteNotice ==============

// ����.
UPartyInviteNotice *UPartyInviteNotice::Create(uint32 CustomerId)
{
	UPartyInviteNotice *pNotice = NewObject<UPartyInviteNotice>();
	pNotice->CustomerId = CustomerId;
	return pNotice;
}

// �R���X�g���N�^
UPartyInviteNotice::UPartyInviteNotice(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// �ʒm�ɑ΂���s��.
void UPartyInviteNotice::Action()
{
}

// ========== UNoticeMenuItem ===============

// �R���X�g���N�^
UNoticeMenuItem::UNoticeMenuItem(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
	, pNotice(nullptr)
{
}


// �ʒm�ɑ΂���s��.
void UNoticeMenuItem::Action()
{
	pNotice->Action();
}
