#include "stdafx.h"
#include "QuestManager.h"
#include "Client.h"
#include "Character/Player/PlayerCharacter.h"
#include "Master/MasterData.h"
#include "CacheServer/CacheServerConnection.h"
#include "Packet/PacketQuestAccept.h"
#include "Packet/PacketQuestClear.h"
#include "Packet/PacketQuestStageChange.h"
#include "Packet/CachePacketSaveQuestDataRequest.h"

// コンストラクタ
QuestManager::QuestManager(Client *pInClient)
	: pClient(pInClient)
{
}

// 追加.
void QuestManager::Add(const QuestData &Data)
{
	Quests[Data.QuestId] = Data;
}

// 受注.
void QuestManager::Accept(u32 QuestId)
{
	QuestData Data(QuestId, 0, 0, QuestData::Active);
	Quests[Data.QuestId] = Data;

	PacketQuestAccept Packet(QuestId);
	pClient->SendPacket(&Packet);

	CachePacketSaveQuestDataRequest CachePacket(pClient->GetUuid(), pClient->GetCharacter().lock()->GetCharacterId(), Data);
	CacheServerConnection::GetInstance()->SendPacket(&CachePacket);
}

// ステージ進行.
void QuestManager::ProgressStage(u32 QuestId)
{
	if (Quests.find(QuestId) == Quests.end()) { return; }

	Quests[QuestId].StageNo++;
	Quests[QuestId].KillCount = 0;

	// クリア判定.
	bool bIsCleared = (GetCurrentStageData(QuestId) == NULL);
	if (bIsCleared)
	{
		Quests[QuestId].State = QuestData::Cleared;

		PacketQuestClear Packet(QuestId);
		pClient->SendPacket(&Packet);

		// メインクエストで次のクエストがあるなら自動受注。
		const QuestItem *pItem = MasterData::GetInstance().GetQuestMaster().GetItem(QuestId);
		if (pItem->Type == QuestItem::MAIN_QUEST && pItem->NextQuestId != 0)
		{
			Accept(pItem->NextQuestId);
		}

		// @TODO:報酬をバラ撒く。
	}
	else
	{
		PacketQuestStageChange Packet(QuestId, Quests[QuestId].StageNo);
		pClient->SendPacket(&Packet);
	}

	CachePacketSaveQuestDataRequest CachePacket(pClient->GetUuid(), pClient->GetCharacter().lock()->GetCharacterId(), Quests[QuestId]);
	CacheServerConnection::GetInstance()->SendPacket(&CachePacket);
}


// 現在のステージ情報を取得.
const QuestStageItem *QuestManager::GetCurrentStageData(u32 QuestId) const
{
	const QuestItem *pQuestItem = MasterData::GetInstance().GetQuestMaster().GetItem(QuestId);
	const QuestStageItem *pStageItem = MasterData::GetInstance().GetQuestStageMaster().GetItem(pQuestItem->StartStageId);
	const QuestData &Data = Quests.find(QuestId)->second;
	for (u32 i = 0; i < Data.StageNo - 1; i++)
	{
		if (pStageItem->NextStageId == 0) { return NULL; }
		pStageItem = MasterData::GetInstance().GetQuestStageMaster().GetItem(pStageItem->NextStageId);
	}

	return pStageItem;
}
