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

// 破棄.
void QuestManager::Retire(u32 QuestId)
{
	if (!Quests.Contains(QuestId)) { return; }
	Quests.Remove(QuestId);
}

// 進行中か？
bool QuestManager::IsActive(u32 QuestId) const
{
	if (!Quests.Contains(QuestId)) { return false; }
	return (Quests[QuestId].State == QuestData::Active);
}

// ステージ番号を取得.
uint32 QuestManager::GetStageNo(u32 QuestId) const
{
	if (!Quests.Contains(QuestId)) { return 0; }
	return Quests[QuestId].StageNo;
}
