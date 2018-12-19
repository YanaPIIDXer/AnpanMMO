#include "stdafx.h"
#include "QuestManager.h"

// コンストラクタ
QuestManager::QuestManager()
{
}

// 追加.
void QuestManager::Add(const QuestData &Data)
{
	Quests[Data.QuestId] = Data;
}
