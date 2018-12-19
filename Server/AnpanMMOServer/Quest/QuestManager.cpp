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
}

// ��.
void QuestManager::Accept(u32 QuestId)
{
	QuestData Data(QuestId, 0, 0, QuestData::Active);
	Quests[Data.QuestId] = Data;

	PacketQuestAccept Packet(QuestId);
	pClient->SendPacket(&Packet);

	CachePacketSaveQuestDataRequest CachePacket(pClient->GetUuid(), pClient->GetCharacter().lock()->GetCharacterId(), Data);
	CacheServerConnection::GetInstance()->SendPacket(&CachePacket);
}

// �X�e�[�W�i�s.
void QuestManager::ProgressStage(u32 QuestId)
{
	if (Quests.find(QuestId) == Quests.end()) { return; }

	const QuestItem *pQuestItem = MasterData::GetInstance().GetQuestMaster().GetItem(QuestId);
	const QuestStageItem *pStageItem = MasterData::GetInstance().GetQuestStageMaster().GetItem(pQuestItem->StartStageId);

	// �N���A����.
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

		// ���C���N�G�X�g�Ŏ��̃N�G�X�g������Ȃ玩���󒍁B
		if (pQuestItem->Type == QuestItem::MAIN_QUEST && pQuestItem->NextQuestId != 0)
		{
			Accept(pQuestItem->NextQuestId);
		}

		// @TODO:��V���o���T���B
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
