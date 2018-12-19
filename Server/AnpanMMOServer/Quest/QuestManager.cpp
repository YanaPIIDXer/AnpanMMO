#include "stdafx.h"
#include "QuestManager.h"
#include "Client.h"
#include "Character/Player/PlayerCharacter.h"
#include "Master/MasterData.h"
#include "CacheServer/CacheServerConnection.h"
#include "Packet/PacketQuestAccept.h"
#include "Packet/PacketQuestAnpanKill.h"
#include "Packet/PacketQuestClear.h"
#include "Packet/PacketQuestStageChange.h"
#include "Packet/PacketQuestRetireResponse.h"
#include "Packet/CachePacketSaveQuestDataRequest.h"
#include "Packet/CachePacketQuestRetireRequest.h"

// コンストラクタ
QuestManager::QuestManager(Client *pInClient)
	: pClient(pInClient)
{
}

// 追加.
void QuestManager::Add(const QuestData &Data)
{
	Quests[Data.QuestId] = Data;
	if (Data.State == QuestData::Active)
	{
		ActiveQuests[Data.QuestId] = &Quests[Data.QuestId];
	}
}

// 受注.
void QuestManager::Accept(u32 QuestId)
{
	QuestData Data(QuestId, 0, 0, QuestData::Active);
	Add(Data);
	
	PacketQuestAccept Packet(QuestId);
	pClient->SendPacket(&Packet);

	CachePacketSaveQuestDataRequest CachePacket(pClient->GetUuid(), pClient->GetCharacter().lock()->GetCharacterId(), Data);
	CacheServerConnection::GetInstance()->SendPacket(&CachePacket);
}

// 破棄.
u8 QuestManager::Retire(u32 QuestId)
{
	if (ActiveQuests.find(QuestId) == ActiveQuests.end()) { return PacketQuestRetireResponse::Error; }
	const QuestItem *pItem = MasterData::GetInstance().GetQuestMaster().GetItem(QuestId);
	if (pItem->Type == QuestItem::MAIN_QUEST) { return PacketQuestRetireResponse::MainQuest; }

	// クエストマップから消去.
	Quests.erase(QuestId);
	ActiveQuests.erase(QuestId);

	// キャッシュサーバにも通知.
	CachePacketQuestRetireRequest Packet(pClient->GetUuid(), pClient->GetCharacter().lock()->GetCharacterId(), QuestId);
	CacheServerConnection::GetInstance()->SendPacket(&Packet);

	return PacketQuestRetireResponse::Success;
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

		// 進行中のクエストマップから消去.
		ActiveQuests.erase(QuestId);

		PacketQuestClear Packet(QuestId);
		pClient->SendPacket(&Packet);

		// メインクエストで次のクエストがあるなら自動受注。
		const QuestItem *pItem = MasterData::GetInstance().GetQuestMaster().GetItem(QuestId);
		if (pItem->Type == QuestItem::MAIN_QUEST && pItem->NextQuestId != 0)
		{
			Accept(pItem->NextQuestId);
		}

		const QuestRewardItem *pRewardItem = MasterData::GetInstance().GetQuestRewardMaster().GetItem(pItem->RewardId);
		if (pRewardItem != NULL)
		{
			switch (pRewardItem->Type)
			{
				case QuestRewardItem::ITEM:

					// アイテム
					pClient->GetCharacter().lock()->AddItem(pRewardItem->ItemId, pRewardItem->Count);
					break;

				case QuestRewardItem::GOLD:

					// ゴールド
					pClient->GetCharacter().lock()->AddGold(pRewardItem->Count);
					break;
			}
		}
	}
	else
	{
		PacketQuestStageChange Packet(QuestId, Quests[QuestId].StageNo);
		pClient->SendPacket(&Packet);
	}

	CachePacketSaveQuestDataRequest CachePacket(pClient->GetUuid(), pClient->GetCharacter().lock()->GetCharacterId(), Quests[QuestId]);
	CacheServerConnection::GetInstance()->SendPacket(&CachePacket);
}

// アンパンを殺害した。
void QuestManager::OnKilledAnpan(u32 AreaId)
{
	for (ActiveQuestMap::iterator It = ActiveQuests.begin(); It != ActiveQuests.end(); ++It)
	{
		const QuestStageItem *pItem = GetCurrentStageData(It->first);
		if (pItem->Condition != QuestStageItem::KILL_ANPAN_IN_AREA || pItem->TargetId != AreaId) { continue; }

		It->second->KillCount++;

		PacketQuestAnpanKill Packet(It->first);
		pClient->SendPacket(&Packet);

		if (It->second->KillCount >= pItem->Count)
		{
			// 規定数殺害したのでステージ進行。
			ProgressStage(It->first);
		}
	}
}

// ステージ番号を取得.
u32 QuestManager::GetStageNo(u32 QuestId) const
{
	QuestMap::const_iterator It = Quests.find(QuestId);
	if (It == Quests.end()) { return 0; }
	return It->second.StageNo;
}


// 現在のステージ情報を取得.
const QuestStageItem *QuestManager::GetCurrentStageData(u32 QuestId) const
{
	const QuestData &Data = Quests.find(QuestId)->second;
	if (Data.State == QuestData::Cleared) { return NULL; }

	const QuestItem *pQuestItem = MasterData::GetInstance().GetQuestMaster().GetItem(QuestId);
	const QuestStageItem *pStageItem = MasterData::GetInstance().GetQuestStageMaster().GetItem(pQuestItem->StartStageId);
	for (u32 i = 0; i < Data.StageNo; i++)
	{
		if (pStageItem == NULL) { return NULL; }
		pStageItem = MasterData::GetInstance().GetQuestStageMaster().GetItem(pStageItem->NextStageId);
	}

	return pStageItem;
}
