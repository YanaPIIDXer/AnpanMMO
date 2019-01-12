// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Packet/QuestData.h"

DECLARE_DELEGATE_OneParam(FOnActiveQuestUpdated, const QuestData *);

class UMMOGameInstance;

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

	// GameInstance��ݒ�B
	// ���{���̓R���X�g���N�^�ł�肽���񂾂��ǁA
	//   �R���X�g���N�^�ł��Ǝ��������R�[�h�œ{����̂Ŏd���Ȃ��̑Ώ��B
	void SetGameInstance(UMMOGameInstance *pInInst) { pInst = pInInst; }

	// ������.
	void Initialize();

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

	// �N���A���Ă��邩�H
	bool IsClear(uint32 QuestId) const;

	// �X�e�[�W�ԍ����擾.
	uint32 GetStageNo(uint32 QuestId) const;

	// �i�s���̃N�G�X�g���.
	TArray<const QuestData *> CollectProgressingQuests() const;

	// �A�N�e�B�u�N�G�X�g��ݒ�.
	void SetActiveQuest(uint32 QuestId, bool bSendSavePacket);

	// �A�N�e�B�u�N�G�X�g�̃f�[�^���擾.
	const QuestData *GetActiveQuestData() const;

	// �A�N�e�B�u�N�G�X�g���X�V���ꂽ�B
	FOnActiveQuestUpdated OnActiveQuestUpdated;

private:

	// �N�G�X�g�}�b�v
	QuestMap Quests;

	// �A�N�e�B�u�N�G�X�g�h�c
	uint32 ActiveQuestId;

	// GameInstance
	TWeakObjectPtr<UMMOGameInstance> pInst;

};
