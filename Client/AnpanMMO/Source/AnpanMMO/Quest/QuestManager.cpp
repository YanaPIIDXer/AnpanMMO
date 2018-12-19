// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "QuestManager.h"

// �R���X�g���N�^
QuestManager::QuestManager()
{
}

// �ǉ�.
void QuestManager::Add(const QuestData &Data)
{
	if (!Quests.Contains(Data.QuestId))
	{
		Quests[Data.QuestId] = Data;
	}
	else
	{
		// �Ƃ肠�����㏑���B
		Quests[Data.QuestId] = Data;
	}
}

// �j��.
void QuestManager::Retire(u32 QuestId)
{
	if (!Quests.Contains(QuestId)) { return; }
	Quests.Remove(QuestId);
}

// �i�s�����H
bool QuestManager::IsActive(u32 QuestId) const
{
	if (!Quests.Contains(QuestId)) { return false; }
	return (Quests[QuestId].State == QuestData::Active);
}

// �X�e�[�W�ԍ����擾.
uint32 QuestManager::GetStageNo(u32 QuestId) const
{
	if (!Quests.Contains(QuestId)) { return 0; }
	return Quests[QuestId].StageNo;
}
