// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Packet/QuestData.h"

/**
 * �N�G�X�g�Ǘ�.
 */
class ANPANMMO_API QuestManager
{

private:	// �ʖ���`.

	typedef TMap<uint32, QuestData> QuestMap;

public:

	// �R���X�g���N�^
	QuestManager();

	// �f�X�g���N�^
	~QuestManager() {}

	// �ǉ�.
	void Add(const QuestData &Data);

	// �A���p���E�Q.
	void KillAnpan(uint32 QuestId);

	// �X�e�[�W�i�s.
	void ProgressStage(uint32 QuestId, uint32 StageNo);

	// �N���A
	void Clear(uint32 QuestId);

	// �j��.
	void Retire(uint32 QuestId);

	// �i�s�����H
	bool IsActive(uint32 QuestId) const;

	// �X�e�[�W�ԍ����擾.
	uint32 GetStageNo(uint32 QuestId) const;

	// �i�s���̃N�G�X�g���.
	TArray<const QuestData *> CollectProgressingQuests() const;

	// �A�N�e�B�u�N�G�X�g��ݒ�.
	void SetActiveQuest(uint32 QuestId) { ActiveQuestId = QuestId; }

	// �A�N�e�B�u�N�G�X�g�̃f�[�^���擾.
	const QuestData *GetActiveQuestData() const;

private:

	// �N�G�X�g�}�b�v
	QuestMap Quests;

	// �A�N�e�B�u�N�G�X�g�h�c
	uint32 ActiveQuestId;

};
