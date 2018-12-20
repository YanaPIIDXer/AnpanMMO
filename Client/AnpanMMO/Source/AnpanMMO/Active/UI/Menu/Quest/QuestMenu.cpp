// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "QuestMenu.h"
#include "MMOGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Master/MasterData.h"

// �R���X�g���N�^
UQuestMenu::UQuestMenu(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
}


// ������.
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
		Data.bIsActive = false;		// @TODO:��őΉ�.
		if (Data.bIsMainQuest)
		{
			// ���C���N�G�X�g�͐擪�ɁB
			DataList.Insert(Data, 0);
		}
		else
		{
			DataList.Add(Data);
		}
	}

	InitEvent(DataList);
}
