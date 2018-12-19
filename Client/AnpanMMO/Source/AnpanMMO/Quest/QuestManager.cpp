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
		Quests.Add(Data.QuestId, Data);
	}
	else
	{
		// とりあえず上書き。
		Quests[Data.QuestId] = Data;
	}
}

// アンパン殺害.
void QuestManager::KillAnpan(uint32 QuestId)
{
	if (!Quests.Contains(QuestId)) { return; }
	Quests[QuestId].KillCount++;
}

// ステージ進行.
void QuestManager::ProgressStage(uint32 QuestId, uint32 StageNo)
{
	if (!Quests.Contains(QuestId)) { return; }
	Quests[QuestId].StageNo = StageNo;
	Quests[QuestId].KillCount = 0;
}

// クリア
void QuestManager::Clear(uint32 QuestId)
{
	if (!Quests.Contains(QuestId)) { return; }
	Quests[QuestId].State = QuestData::Cleared;
}

// 破棄.
void QuestManager::Retire(uint32 QuestId)
{
	if (!Quests.Contains(QuestId)) { return; }
	Quests.Remove(QuestId);
}

// 進行中か？
bool QuestManager::IsActive(uint32 QuestId) const
{
	if (!Quests.Contains(QuestId)) { return false; }
	return (Quests[QuestId].State == QuestData::Active);
}

// ステージ番号を取得.
uint32 QuestManager::GetStageNo(uint32 QuestId) const
{
	if (!Quests.Contains(QuestId)) { return 0; }
	return Quests[QuestId].StageNo;
}
