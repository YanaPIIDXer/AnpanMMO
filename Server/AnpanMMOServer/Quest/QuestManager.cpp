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

	const QuestItem *pQuestItem = MasterData::GetInstance().GetQuestMaster().GetItem(QuestId);
	const QuestStageItem *pStageItem = MasterData::GetInstance().GetQuestStageMaster().GetItem(pQuestItem->StartStageId);

	// クリア判定.
	bool bIsCleared = false;
	for (u32 i = 0; i < Quests[QuestId].StageNo; i++)
	{
		if (pStageItem->NextStageId == 0)
		{
			bIsCleared = true;
			break;
		}
		pStageItem = MasterData::GetInstance().GetQuestStageMaster().GetItem(pStageItem->NextStageId);
	}
	if (bIsCleared)
	{
		Quests[QuestId].State = QuestData::Cleared;

		PacketQuestClear Packet(QuestId);
		pClient->SendPacket(&Packet);

		// メインクエストで次のクエストがあるなら自動受注。
		if (pQuestItem->Type == QuestItem::MAIN_QUEST && pQuestItem->NextQuestId != 0)
		{
			Accept(pQuestItem->NextQuestId);
		}

		// @TODO:報酬をバラ撒く。
	}
	else
	{
		Quests[QuestId].StageNo++;
		Quests[QuestId].KillCount = 0;

		PacketQuestStageChange Packet(QuestId, Quests[QuestId].StageNo);
		pClient->SendPacket(&Packet);
	}

	CachePacketSaveQuestDataRequest CachePacket(pClient->GetUuid(), pClient->GetCharacter().lock()->GetCharacterId(), Quests[QuestId]);
	CacheServerConnection::GetInstance()->SendPacket(&CachePacket);
}
