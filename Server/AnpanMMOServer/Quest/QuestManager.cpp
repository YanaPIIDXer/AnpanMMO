#include "stdafx.h"
#include "QuestManager.h"

// �R���X�g���N�^
QuestManager::QuestManager()
{
}

// �ǉ�.
void QuestManager::Add(const QuestData &Data)
{
	Quests[Data.QuestId] = Data;
}
