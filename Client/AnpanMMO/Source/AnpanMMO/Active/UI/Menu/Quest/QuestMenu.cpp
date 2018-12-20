// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "QuestMenu.h"
#include "MMOGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Master/MasterData.h"

// コンストラクタ
UQuestMenu::UQuestMenu(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
}


// 初期化.
void UQuestMenu::Init()
{
	UMMOGameInstance *pInst = Cast<UMMOGameInstance>(UGameplayStatics::GetGameInstance(this));
	check(pInst != nullptr);

	TArray<const QuestData *> List = pInst->GetQuestManager().CollectProgressingQuests();
	TArray<FQuestData> DataList;
	for (const auto *pData : List)
	{
		const QuestItem *pItem = MasterData::GetInstance().GetQuestMaster().Get(pData->QuestId);
		check(pItem != nullptr);

		FQuestData Data;
		Data.QuestId = pItem->Id;
		Data.Name = pItem->Name;
		Data.Explain = pItem->Explain;
		Data.bIsMainQuest = (pItem->Type == QuestItem::MAIN_QUEST);
		Data.bIsActive = false;		// @TODO:後で対応.
		if (Data.bIsMainQuest)
		{
			// メインクエストは先頭に。
			DataList.Insert(Data, 0);
		}
		else
		{
			DataList.Add(Data);
		}
	}

	InitEvent(DataList);
}
