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

// �R���X�g���N�^
QuestManager::QuestManager(Client *pInClient)
	: pClient(pInClient)
{
}

// �ǉ�.
void QuestManager::Add(const QuestData &Data)
{
	Quests[Data.QuestId] = Data;
	if (Data.State == QuestData::Active)
	{
		ActiveQuests[Data.QuestId] = &Quests[Data.QuestId];
	}
}

// ��.
void QuestManager::Accept(u32 QuestId)
{
	QuestData Data(QuestId, 0, 0, QuestData::Active);
	Add(Data);
	
	PacketQuestAccept Packet(QuestId);
	pClient->SendPacket(&Packet);

	CachePacketSaveQuestDataRequest CachePacket(pClient->GetUuid(), pClient->GetCharacter().lock()->GetCharacterId(), Data);
	CacheServerConnection::GetInstance()->SendPacket(&CachePacket);
}

// �X�e�[�W�i�s.
void QuestManager::ProgressStage(u32 QuestId)
{
	if (Quests.find(QuestId) == Quests.end()) { return; }

	Quests[QuestId].StageNo++;
	Quests[QuestId].KillCount = 0;

	// �N���A����.
	bool bIsCleared = (GetCurrentStageData(QuestId) == NULL);
	if (bIsCleared)
	{
		Quests[QuestId].State = QuestData::Cleared;

		// �i�s���̃N�G�X�g�}�b�v���������.
		ActiveQuests.erase(QuestId);

		PacketQuestClear Packet(QuestId);
		pClient->SendPacket(&Packet);

		// ���C���N�G�X�g�Ŏ��̃N�G�X�g������Ȃ玩���󒍁B
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

					// �A�C�e��
					pClient->GetCharacter().lock()->AddItem(pRewardItem->ItemId, pRewardItem->Count);
					break;

				case QuestRewardItem::GOLD:

					// �S�[���h
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

// �A���p�����E�Q�����B
void QuestManager::OnKilledAnpan(u32 AreaId)
{
	for (ActiveQuestMap::iterator It = ActiveQuests.begin(); It != ActiveQuests.end(); ++It)
	{
		const QuestStageItem *pItem = GetCurrentStageData(It->first);
		if (pItem->Condition != QuestStageItem::KILL_ANPAN_IN_AREA || pItem->TargetId != AreaId) { continue; }

		It->second->KillCount++;
		if (It->second->KillCount >= pItem->Count)
		{
			// �K�萔�E�Q�����̂ŃX�e�[�W�i�s�B
			ProgressStage(It->first);
		}
	}
}


// ���݂̃X�e�[�W�����擾.
const QuestStageItem *QuestManager::GetCurrentStageData(u32 QuestId) const
{
	const QuestData &Data = Quests.find(QuestId)->second;
	if (Data.State == QuestData::Cleared) { return NULL; }

	const QuestItem *pQuestItem = MasterData::GetInstance().GetQuestMaster().GetItem(QuestId);
	const QuestStageItem *pStageItem = MasterData::GetInstance().GetQuestStageMaster().GetItem(pQuestItem->StartStageId);
	for (u32 i = 0; i < Data.StageNo - 1; i++)
	{
		if (pStageItem->NextStageId == 0) { return NULL; }
		pStageItem = MasterData::GetInstance().GetQuestStageMaster().GetItem(pStageItem->NextStageId);
	}

	return pStageItem;
}
