// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "NoticeMenuWidget.h"
#include "Util.h"
#include "Kismet/GameplayStatics.h"
#include "Active/ActiveGameMode.h"
#include "Packet/NoticeData.h"

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

// �R���X�g���N�^
UNoticeBase::UNoticeBase(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
	, CustomerId(0)
	, NoticeUuid(0)
	, CharacterName("")
{
}

// �ʒm�ɑ΂���s��.
void UNoticeBase::Action()
{
	OnAction();

	AActiveGameMode *pGameMode = Cast<AActiveGameMode>(UGameplayStatics::GetGameMode(this));
	check(pGameMode != nullptr);

	pGameMode->RemoveNotice(NoticeUuid);
}

// ========== UPartyInviteNotice ==============

// ����.
UPartyInviteNotice *UPartyInviteNotice::Create(UObject *pOuter, uint32 NoticeUuid, uint32 CustomerId, const FString &CharacterName)
{
	UPartyInviteNotice *pNotice = NewObject<UPartyInviteNotice>(pOuter);
	pNotice->NoticeUuid = NoticeUuid;
	pNotice->CustomerId = CustomerId;
	pNotice->CharacterName = CharacterName;
	return pNotice;
}

// �R���X�g���N�^
UPartyInviteNotice::UPartyInviteNotice(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// �ʒm�ɑ΂���s��.
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

// �R���X�g���N�^
UNoticeMenuItem::UNoticeMenuItem(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
	, pParent(nullptr)
	, pNotice(nullptr)
{
}


// �ʒm�ɑ΂���s��.
void UNoticeMenuItem::Action()
{
	pNotice->Action();
	pParent->Close();
}

// ========== UPartyInviteNoticeItem =============

// �R���X�g���N�^
UPartyInviteNoticeItem::UPartyInviteNoticeItem(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
}


// ���U���󂯂邩�ǂ�����ݒ�.
void UPartyInviteNoticeItem::SetAccept(bool bAccept)
{
	UPartyInviteNotice *pPartyInviteNotice = Cast<UPartyInviteNotice>(pNotice);
	check(pPartyInviteNotice != nullptr);

	pPartyInviteNotice->SetAccept(bAccept);
}
