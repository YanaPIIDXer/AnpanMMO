// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "QuestManager.h"
#include "MMOGameInstance.h"
#include "Packet/PacketSaveActiveQuest.h"

// コンストラクタ
QuestManager::QuestManager()
	: ActiveQuestId(0)
	, pInst(nullptr)
{
}

// 初期化.
void QuestManager::Initialize()
{
	Quests.Empty();
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

// 進行中のクエストを列挙.
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

// アクティブクエストを設定.
void QuestManager::SetActiveQuest(uint32 QuestId, bool bSendSavePacket)
{
	ActiveQuestId = QuestId;
	if (bSendSavePacket)
	{
		PacketSaveActiveQuest Packet(QuestId);
		pInst->SendPacket(&Packet);
	}
}


// アクティブクエストのデータを取得.
const QuestData *QuestManager::GetActiveQuestData() const
{
	if (!Quests.Contains(ActiveQuestId)) { return nullptr; }
	return &Quests[ActiveQuestId];
}
