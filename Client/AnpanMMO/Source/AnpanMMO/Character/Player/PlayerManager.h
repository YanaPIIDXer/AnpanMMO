// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PlayerCharacterBase.h"

/**
 * �v���C���[�Ǘ�.
 */
class ANPANMMO_API PlayerManager
{

private:		// �ʖ���`.

	typedef TWeakObjectPtr<APlayerCharacterBase> PlayerPtr;
	
public:

	// �R���X�g���N�^
	PlayerManager();

	// �f�X�g���N�^
	~PlayerManager() {}

	// �ǉ�.
	void Add(uint8 Uuid, APlayerCharacterBase *pPlayer);

	// �擾.
	APlayerCharacterBase *Get(uint32 Uuid) const;

private:

	// �v���C���[�}�b�v
	TMap<uint8, PlayerPtr> PlayerMap;

};