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
