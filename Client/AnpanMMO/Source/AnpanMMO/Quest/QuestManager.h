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

private:

	// �N�G�X�g�}�b�v
	QuestMap Quests;

};
