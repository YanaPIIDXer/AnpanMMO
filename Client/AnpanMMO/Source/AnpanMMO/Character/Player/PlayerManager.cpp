// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "PlayerManager.h"

// �R���X�g���N�^
PlayerManager::PlayerManager()
{
}

// �ǉ�.
void PlayerManager::Add(uint8 Uuid, APlayerCharacterBase *pPlayer)
{
	PlayerMap.Add(Uuid, pPlayer);
}

// �擾.
APlayerCharacterBase *PlayerManager::Get(uint32 Uuid) const
{
	if (PlayerMap.Contains(Uuid)) { return nullptr; }
	return PlayerMap[Uuid].Get();
}
