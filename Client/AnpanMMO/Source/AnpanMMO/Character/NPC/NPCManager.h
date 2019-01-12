// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

class ANPCCharacter;

/**
 * NPC�Ǘ��N���X
 */
class ANPANMMO_API NPCManager
{

public:

	// �R���X�g���N�^
	NPCManager();

	// �f�X�g���N�^
	~NPCManager() {}

	// World��ݒ�.
	void SetWorld(UWorld *pInWorld) { pWorld = pInWorld; }

	// �}�b�v���؂�ւ�����B
	void OnMapChanegd(uint32 MapId);

	// ���Z�b�g�B
	void Reset();

private:

	// World
	TWeakObjectPtr<UWorld> pWorld;

	// NPC���X�g
	TArray<TWeakObjectPtr<ANPCCharacter>> NPCs;

};
