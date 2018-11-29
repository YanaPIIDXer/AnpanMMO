// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "NoticeMenuWidget.h"
#include "Util.h"
#include "Kismet/GameplayStatics.h"
#include "Active/ActiveGameMode.h"
#include "Packet/NoticeData.h"

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
	
	AActiveGameMode *pGameMode = Cast<AActiveGameMode>(UGameplayStatics::GetGameMode(this));
	check(pGameMode != nullptr);

	TArray<NoticeInformation> Notices = pGameMode->GetNoticeList();
	for (const auto &Info : Notices)
	{
		UNoticeBase *pNotice = nullptr;
		switch (Info.Data.Type)
		{
			case NoticeData::PartyInvide:

				pNotice = UPartyInviteNotice::Create(this, Info.Uuid, Info.Data.CustomerId, "DummyName");
				break;
		}
		check(pNotice != nullptr);
		NoticeList.Add(pNotice);
	}

	OnInit();
}

// ============ UNoticeBase ===============

// コンストラクタ
UNoticeBase::UNoticeBase(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
	, CustomerId(0)
	, NoticeUuid(0)
	, CharacterName("")
{
}

// 通知に対する行動.
void UNoticeBase::Action()
{
	OnAction();

	AActiveGameMode *pGameMode = Cast<AActiveGameMode>(UGameplayStatics::GetGameMode(this));
	check(pGameMode != nullptr);

	pGameMode->RemoveNotice(NoticeUuid);
}

// ========== UPartyInviteNotice ==============

// 生成.
UPartyInviteNotice *UPartyInviteNotice::Create(UObject *pOuter, uint32 NoticeUuid, uint32 CustomerId, const FString &CharacterName)
{
	UPartyInviteNotice *pNotice = NewObject<UPartyInviteNotice>(pOuter);
	pNotice->NoticeUuid = NoticeUuid;
	pNotice->CustomerId = CustomerId;
	pNotice->CharacterName = CharacterName;
	return pNotice;
}

// コンストラクタ
UPartyInviteNotice::UPartyInviteNotice(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// 通知に対する行動.
void UPartyInviteNotice::OnAction()
{
	if (bAccept)
	{
		UE_LOG(LogTemp, Log, TEXT("Accept Party Invite."));
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("Refuse Party Invite"));
	}
}

// ========== UNoticeMenuItem ===============

// コンストラクタ
UNoticeMenuItem::UNoticeMenuItem(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
	, pParent(nullptr)
	, pNotice(nullptr)
{
}


// 通知に対する行動.
void UNoticeMenuItem::Action()
{
	pNotice->Action();
	pParent->Close();
}

// ========== UPartyInviteNoticeItem =============

// コンストラクタ
UPartyInviteNoticeItem::UPartyInviteNoticeItem(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
}


// 勧誘を受けるかどうかを設定.
void UPartyInviteNoticeItem::SetAccept(bool bAccept)
{
	UPartyInviteNotice *pPartyInviteNotice = Cast<UPartyInviteNotice>(pNotice);
	check(pPartyInviteNotice != nullptr);

	pPartyInviteNotice->SetAccept(bAccept);
}
