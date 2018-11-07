// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "PlayerManager.h"
#include "Packet/PacketSpawnPlayer.h"
#include "MemoryStream/MemoryStreamInterface.h"

// �R���X�g���N�^
PlayerManager::PlayerManager()
	: pWorld(nullptr)
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

// ��������M.
void PlayerManager::OnRecvSpawn(MemoryStreamInterface *pStream)
{
	PacketSpawnPlayer Packet;
	Packet.Serialize(pStream);

	UE_LOG(LogTemp, Log, TEXT("SpawnPlayer UUID:%d"), Packet.Uuid);
}
