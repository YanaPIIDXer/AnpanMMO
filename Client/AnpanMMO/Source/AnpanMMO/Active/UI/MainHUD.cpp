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

// 表示.
UMainHUD *UMainHUD::Show(UObject *pOuter)
{
	auto *pWidget = Util::LoadBlueprint<UMainHUD>(pOuter, AssetPath);
	check(pWidget != nullptr);

	pWidget->AddToViewport();
	return pWidget;
}

// コンストラクタ
UMainHUD::UMainHUD(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
	, pCharacter(nullptr)
	, NotReadNoticeCount(0)
{
}

// 開始時の処理.
void UMainHUD::NativeConstruct()
{
	Super::NativeConstruct();

	pCharacter = Cast<AGameCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));

	UMMOGameInstance *pInst = Cast<UMMOGameInstance>(UGameplayStatics::GetGameInstance(this));
	check(pInst != nullptr);
	pInst->OnActiveQuestUpdated().BindUObject<UMainHUD>(this, &UMainHUD::OnActiveQuestUpdated);

	OnActiveQuestUpdated(pInst->GetActiveQuestData());
}

// アイテムショートカット更新.
void UMainHUD::UpdateItemShortcut()
{
	TArray<int32> ItemShortcut = pCharacter->GetItemShortcutForBlurprint();
	OnUpdateItemShortcut(ItemShortcut);
}

// 通知を受信した。
void UMainHUD::OnRecvNotice(int32 Uuid, const NoticeData &Data)
{
	NotReadNoticeCount++;
}


// レベルロード開始.
void UMainHUD::StartLevelLoad()
{
	UMMOGameInstance *pInst = Cast<UMMOGameInstance>(UGameplayStatics::GetGameInstance(this));
	check(pInst != nullptr);

	AActiveGameMode *pGameMode = Cast<AActiveGameMode>(UGameplayStatics::GetGameMode(this));
	check(pGameMode != nullptr);
	
	uint32 AreaId = pInst->GetAreaIdCache();
	pGameMode->StartLevelLoad(AreaId);
}

// ゲームメニューを表示.
void UMainHUD::ShowGameMenu()
{
	UGameMenuWidget::ShowWidget(this);
}

// 通知メニューを表示.
void UMainHUD::ShowNoticeMenu()
{
	NotReadNoticeCount = 0;
	UNoticeMenuWidget::ShowWidget(this);
}

// アクティブクエストの情報を表示.
void UMainHUD::ShowActiveQuestData()
{
	UMMOGameInstance *pInst = Cast<UMMOGameInstance>(UGameplayStatics::GetGameInstance(this));
	check(pInst != nullptr);

	OnActiveQuestUpdated(pInst->GetActiveQuestData());

}


// アクティブクエストが更新された。
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
