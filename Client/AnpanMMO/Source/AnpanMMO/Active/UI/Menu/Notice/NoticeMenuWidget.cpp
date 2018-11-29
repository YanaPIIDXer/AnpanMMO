// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "NoticeMenuWidget.h"
#include "Util.h"

const TCHAR *UNoticeMenuWidget::AssetPath = TEXT("/Game/Blueprints/UI/Active/Menu/Notice/NoticeMenu.NoticeMenu");

// 表示.
void UNoticeMenuWidget::ShowWidget(UObject *pOuter)
{
	UNoticeMenuWidget *pWidget = Util::LoadBlueprint<UNoticeMenuWidget>(pOuter, AssetPath);
	check(pWidget != nullptr);

	pWidget->Show();
}

// コンストラクタ
UNoticeMenuWidget::UNoticeMenuWidget(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// 開始時の処理.
void UNoticeMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();


}

// ============ UNoticeBase ===============

// コンストラクタ
UNoticeBase::UNoticeBase(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// ========== UPartyInviteNotice ==============

// 生成.
UPartyInviteNotice *UPartyInviteNotice::Create(uint32 CustomerId)
{
	UPartyInviteNotice *pNotice = NewObject<UPartyInviteNotice>();
	pNotice->CustomerId = CustomerId;
	return pNotice;
}

// コンストラクタ
UPartyInviteNotice::UPartyInviteNotice(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// 通知に対する行動.
void UPartyInviteNotice::Action()
{
}

// ========== UNoticeMenuItem ===============

// コンストラクタ
UNoticeMenuItem::UNoticeMenuItem(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
	, pNotice(nullptr)
{
}


// 通知に対する行動.
void UNoticeMenuItem::Action()
{
	pNotice->Action();
}
