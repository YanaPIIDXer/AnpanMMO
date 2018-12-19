// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "QuestManager.h"

// コンストラクタ
QuestManager::QuestManager()
{
}

// 追加.
void QuestManager::Add(const QuestData &Data)
{
	if (!Quests.Contains(Data.QuestId))
	{
		Quests[Data.QuestId] = Data;
	}
	else
	{
		// とりあえず上書き。
		Quests[Data.QuestId] = Data;
	}
}
