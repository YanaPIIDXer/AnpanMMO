// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "QuestMenu.h"
#include "MMOGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Master/MasterData.h"
#include "Packet/PacketQuestRetireRequest.h"
#include "Packet/PacketSaveActiveQuest.h"

// コンストラクタ
UQuestMenu::UQuestMenu(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// パケットを受信した。
void UQuestMenu::OnRecvPacket(uint8 ID)
{
	switch (ID)
	{
		case PacketID::QuestRetireResponse:

			// クエスト破棄受信後は再構築.
			Init();
			break;
	}
}


// 初期化.
void UQuestMenu::Init()
{
	UMMOGameInstance *pInst = Cast<UMMOGameInstance>(UGameplayStatics::GetGameInstance(this));
	check(pInst != nullptr);

	TArray<const QuestData *> List = pInst->GetQuestManager().CollectProgressingQuests();
	TArray<FQuestData> DataList;

	const QuestData *pActiveQuestData = pInst->GetActiveQuestData();
	for (const auto *pData : List)
	{
		const QuestItem *pItem = MasterData::GetInstance().GetQuestMaster().Get(pData->QuestId);
		check(pItem != nullptr);

		FQuestData Data;
		Data.QuestId = pItem->Id;
		Data.Name = pItem->Name;
		Data.Explain = pItem->Explain;
		Data.bIsMainQuest = (pItem->Type == QuestItem::MAIN_QUEST);
		Data.bIsActive = (pActiveQuestData != nullptr && pActiveQuestData->QuestId == pItem->Id);
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

// クエスト破棄.
void UQuestMenu::RetireQuest(const FQuestData &Data)
{
	PacketQuestRetireRequest Packet(Data.QuestId);

	UMMOGameInstance *pInst = Cast<UMMOGameInstance>(UGameplayStatics::GetGameInstance(this));
	check(pInst != nullptr);

	pInst->SendPacket(&Packet);
}

// アクティブクエストを変更.
void UQuestMenu::ChangeActiveQuest(const FQuestData &Data)
{
	PacketSaveActiveQuest Packet(Data.QuestId);

	UMMOGameInstance *pInst = Cast<UMMOGameInstance>(UGameplayStatics::GetGameInstance(this));
	check(pInst != nullptr);

	pInst->SetActiveQuest(Data.QuestId);

	pInst->SendPacket(&Packet);
}
