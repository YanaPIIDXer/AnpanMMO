// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "QuestMenu.h"
#include "MMOGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Master/MasterData.h"
#include "Packet/PacketQuestRetireRequest.h"
#include "Packet/PacketSaveActiveQuest.h"

// �R���X�g���N�^
UQuestMenu::UQuestMenu(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// �p�P�b�g����M�����B
void UQuestMenu::OnRecvPacket(uint8 ID)
{
	switch (ID)
	{
		case PacketID::QuestRetireResponse:

			// �N�G�X�g�j����M��͍č\�z.
			Init();
			break;
	}
}


// ������.
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

// �N�G�X�g�j��.
void UQuestMenu::RetireQuest(const FQuestData &Data)
{
	PacketQuestRetireRequest Packet(Data.QuestId);

	UMMOGameInstance *pInst = Cast<UMMOGameInstance>(UGameplayStatics::GetGameInstance(this));
	check(pInst != nullptr);

	pInst->SendPacket(&Packet);
}

// �A�N�e�B�u�N�G�X�g��ύX.
void UQuestMenu::ChangeActiveQuest(const FQuestData &Data)
{
	PacketSaveActiveQuest Packet(Data.QuestId);

	UMMOGameInstance *pInst = Cast<UMMOGameInstance>(UGameplayStatics::GetGameInstance(this));
	check(pInst != nullptr);

	pInst->SetActiveQuest(Data.QuestId);

	pInst->SendPacket(&Packet);
}
