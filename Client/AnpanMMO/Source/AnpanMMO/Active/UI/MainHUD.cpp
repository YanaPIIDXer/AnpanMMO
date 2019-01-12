// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#include "MainHUD.h"
#include "Util.h"
#include "Character/Player/GameCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "MMOGameInstance.h"
#include "Active/ActiveGameMode.h"
#include "Packet/NoticeData.h"
#include "Menu/GameMenuWidget.h"
#include "Menu/Notice/NoticeMenuWidget.h"
#include "Master/MasterData.h"
#include "Packet/QuestData.h"

const TCHAR *UMainHUD::AssetPath = TEXT("/Game/Blueprints/UI/Active/MainHUD.MainHUD");

// �\��.
UMainHUD *UMainHUD::Show(UObject *pOuter)
{
	auto *pWidget = Util::LoadBlueprint<UMainHUD>(pOuter, AssetPath);
	check(pWidget != nullptr);

	pWidget->AddToViewport();
	return pWidget;
}

// �R���X�g���N�^
UMainHUD::UMainHUD(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
	, pCharacter(nullptr)
	, NotReadNoticeCount(0)
{
}

// �J�n���̏���.
void UMainHUD::NativeConstruct()
{
	Super::NativeConstruct();

	pCharacter = Cast<AGameCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));

	UMMOGameInstance *pInst = Cast<UMMOGameInstance>(UGameplayStatics::GetGameInstance(this));
	check(pInst != nullptr);
	pInst->OnActiveQuestUpdated().BindUObject<UMainHUD>(this, &UMainHUD::OnActiveQuestUpdated);

	OnActiveQuestUpdated(pInst->GetActiveQuestData());
}

// �A�C�e���V���[�g�J�b�g�X�V.
void UMainHUD::UpdateItemShortcut()
{
	TArray<int32> ItemShortcut = pCharacter->GetItemShortcutForBlurprint();
	OnUpdateItemShortcut(ItemShortcut);
}

// �ʒm����M�����B
void UMainHUD::OnRecvNotice(int32 Uuid, const NoticeData &Data)
{
	NotReadNoticeCount++;
}


// ���x�����[�h�J�n.
void UMainHUD::StartLevelLoad()
{
	UMMOGameInstance *pInst = Cast<UMMOGameInstance>(UGameplayStatics::GetGameInstance(this));
	check(pInst != nullptr);

	AActiveGameMode *pGameMode = Cast<AActiveGameMode>(UGameplayStatics::GetGameMode(this));
	check(pGameMode != nullptr);
	
	uint32 AreaId = pInst->GetAreaIdCache();
	pGameMode->StartLevelLoad(AreaId);
}

// �Q�[�����j���[��\��.
void UMainHUD::ShowGameMenu()
{
	UGameMenuWidget::ShowWidget(this);
}

// �ʒm���j���[��\��.
void UMainHUD::ShowNoticeMenu()
{
	NotReadNoticeCount = 0;
	UNoticeMenuWidget::ShowWidget(this);
}

// �A�N�e�B�u�N�G�X�g�̏���\��.
void UMainHUD::ShowActiveQuestData()
{
	UMMOGameInstance *pInst = Cast<UMMOGameInstance>(UGameplayStatics::GetGameInstance(this));
	check(pInst != nullptr);

	OnActiveQuestUpdated(pInst->GetActiveQuestData());

}


// �A�N�e�B�u�N�G�X�g���X�V���ꂽ�B
void UMainHUD::OnActiveQuestUpdated(const QuestData *pQuestData)
{
	if (pQuestData == nullptr || pQuestData->State == QuestData::Cleared)
	{
		OnActiveQuestUpdatedEvent(EQuestType::None, 0, 0, 0);
		return;
	}

	const QuestItem *pItem = MasterData::GetInstance().GetQuestMaster().Get(pQuestData->QuestId);
	check(pItem != nullptr);

	const QuestStageItem *pStageItem = MasterData::GetInstance().GetQuestStageMaster().Get(pItem->StartStageId);
	for (uint32 i = 0; i < pQuestData->StageNo; i++)
	{
		pStageItem = MasterData::GetInstance().GetQuestStageMaster().Get(pStageItem->NextStageId);
	}
	check(pStageItem != nullptr);

	EQuestType Type = EQuestType::None;
	switch (pStageItem->Condition)
	{
		case QuestStageItem::NPC:

			Type = EQuestType::TalkNPC;
			break;

		case QuestStageItem::KILL_ANPAN_IN_AREA:

			Type = EQuestType::KillAnpan;
			break;

		case QuestStageItem::COLLECT_ITEM:

			Type = EQuestType::CollectItem;
			break;
	}

	OnActiveQuestUpdatedEvent(Type, pStageItem->TargetId, pQuestData->KillCount, pStageItem->Count);
}
