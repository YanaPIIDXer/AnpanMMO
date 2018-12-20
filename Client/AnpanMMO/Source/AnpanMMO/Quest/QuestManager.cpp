// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "QuestManager.h"
#include "MMOGameInstance.h"
#include "Master/MasterData.h"
#include "Packet/PacketSaveActiveQuest.h"

// �R���X�g���N�^
QuestManager::QuestManager()
	: ActiveQuestId(0)
	, pInst(nullptr)
{
}

// ������.
void QuestManager::Initialize()
{
	Quests.Empty();
}

// �ǉ�.
void QuestManager::Add(const QuestData &Data)
{
	if (!Quests.Contains(Data.QuestId))
	{
		Quests.Add(Data.QuestId, Data);
	}
	else
	{
		// �Ƃ肠�����㏑���B
		Quests[Data.QuestId] = Data;
	}

	const QuestItem *pItem = MasterData::GetInstance().GetQuestMaster().Get(Data.QuestId);
	check(pItem != nullptr);
	const QuestItem *pActiveItem = MasterData::GetInstance().GetQuestMaster().Get(ActiveQuestId);
	if (pActiveItem == nullptr) { return; }

	// �A�N�e�B�u�N�G�X�g�����C���N�G�X�g�������ꍇ�A
	// �����󒍂����N�G�X�g�����C���N�G�X�g�������ꍇ�A
	// �A�N�e�B�u�N�G�X�g��V�������C���N�G�X�g�ɕύX����B
	if (pItem->Type == QuestItem::MAIN_QUEST && pActiveItem->Type == QuestItem::MAIN_QUEST)
	{
		SetActiveQuest(Data.QuestId, true);
	}
}

// �A���p���E�Q.
void QuestManager::KillAnpan(uint32 QuestId)
{
	if (!Quests.Contains(QuestId)) { return; }
	Quests[QuestId].KillCount++;
	if (QuestId == ActiveQuestId)
	{
		OnActiveQuestUpdated.ExecuteIfBound(&Quests[QuestId]);
	}
}

// �X�e�[�W�i�s.
void QuestManager::ProgressStage(uint32 QuestId, uint32 StageNo)
{
	if (!Quests.Contains(QuestId)) { return; }
	Quests[QuestId].StageNo = StageNo;
	Quests[QuestId].KillCount = 0;
	if (QuestId == ActiveQuestId)
	{
		OnActiveQuestUpdated.ExecuteIfBound(&Quests[QuestId]);
	}
}

// �N���A
void QuestManager::Clear(uint32 QuestId)
{
	if (!Quests.Contains(QuestId)) { return; }
	Quests[QuestId].State = QuestData::Cleared;
	if (QuestId == ActiveQuestId)
	{
		OnActiveQuestUpdated.ExecuteIfBound(&Quests[QuestId]);
	}
}

// �j��.
void QuestManager::Retire(uint32 QuestId)
{
	if (!Quests.Contains(QuestId)) { return; }
	Quests.Remove(QuestId);
}

// �i�s�����H
bool QuestManager::IsActive(uint32 QuestId) const
{
	if (!Quests.Contains(QuestId)) { return false; }
	return (Quests[QuestId].State == QuestData::Active);
}

// �X�e�[�W�ԍ����擾.
uint32 QuestManager::GetStageNo(uint32 QuestId) const
{
	if (!Quests.Contains(QuestId)) { return 0; }
	return Quests[QuestId].StageNo;
}

// �i�s���̃N�G�X�g���.
TArray<const QuestData *> QuestManager::CollectProgressingQuests() const
{
	TArray<const QuestData *> List;
	for (const auto &KeyValue : Quests)
	{
		if (KeyValue.Value.State == QuestData::Active)
		{
			List.Add(&KeyValue.Value);
		}
	}

	return List;
}

// �A�N�e�B�u�N�G�X�g��ݒ�.
void QuestManager::SetActiveQuest(uint32 QuestId, bool bSendSavePacket)
{
	ActiveQuestId = QuestId;

	if (Quests.Contains(QuestId))
	{
		OnActiveQuestUpdated.ExecuteIfBound(&Quests[QuestId]);
	}
	else
	{
		OnActiveQuestUpdated.ExecuteIfBound(nullptr);
	}

	if (bSendSavePacket)
	{
		PacketSaveActiveQuest Packet(QuestId);
		pInst->SendPacket(&Packet);
	}
}


// �A�N�e�B�u�N�G�X�g�̃f�[�^���擾.
const QuestData *QuestManager::GetActiveQuestData() const
{
	if (!Quests.Contains(ActiveQuestId)) { return nullptr; }
	return &Quests[ActiveQuestId];
}
