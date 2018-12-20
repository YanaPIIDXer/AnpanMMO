// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "QuestManager.h"
#include "MMOGameInstance.h"
#include "Master/MasterData.h"
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

	const QuestItem *pItem = MasterData::GetInstance().GetQuestMaster().Get(Data.QuestId);
	check(pItem != nullptr);
	const QuestItem *pActiveItem = MasterData::GetInstance().GetQuestMaster().Get(ActiveQuestId);
	if (pActiveItem == nullptr) { return; }

	// アクティブクエストがメインクエストだった場合、
	// 尚且つ受注したクエストがメインクエストだった場合、
	// アクティブクエストを新しいメインクエストに変更する。
	if (pItem->Type == QuestItem::MAIN_QUEST && pActiveItem->Type == QuestItem::MAIN_QUEST)
	{
		SetActiveQuest(Data.QuestId, true);
	}
}

// アンパン殺害.
void QuestManager::KillAnpan(uint32 QuestId)
{
	if (!Quests.Contains(QuestId)) { return; }
	Quests[QuestId].KillCount++;
	if (QuestId == ActiveQuestId)
	{
		OnActiveQuestUpdated.ExecuteIfBound(&Quests[QuestId]);
	}
}

// ステージ進行.
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

// クリア
void QuestManager::Clear(uint32 QuestId)
{
	if (!Quests.Contains(QuestId)) { return; }
	Quests[QuestId].State = QuestData::Cleared;
	if (QuestId == ActiveQuestId)
	{
		OnActiveQuestUpdated.ExecuteIfBound(&Quests[QuestId]);
	}
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


// アクティブクエストのデータを取得.
const QuestData *QuestManager::GetActiveQuestData() const
{
	if (!Quests.Contains(ActiveQuestId)) { return nullptr; }
	return &Quests[ActiveQuestId];
}
