// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "PlayerManager.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "Packet/PacketSpawnPlayer.h"
#include "Packet/PacketPlayerList.h"

// コンストラクタ
PlayerManager::PlayerManager()
	: pWorld(nullptr)
{
}

// 追加.
void PlayerManager::Add(uint8 Uuid, APlayerCharacterBase *pPlayer)
{
	PlayerMap.Add(Uuid, pPlayer);
}

// 取得.
APlayerCharacterBase *PlayerManager::Get(uint32 Uuid) const
{
	if (PlayerMap.Contains(Uuid)) { return nullptr; }
	return PlayerMap[Uuid].Get();
}

// 生成を受信.
void PlayerManager::OnRecvSpawn(MemoryStreamInterface *pStream)
{
	PacketSpawnPlayer Packet;
	Packet.Serialize(pStream);

	UE_LOG(LogTemp, Log, TEXT("SpawnPlayer UUID:%d"), Packet.Uuid);
}

// リストを受信.
void PlayerManager::OnRecvList(MemoryStreamInterface *pStream)
{
	PacketPlayerList Packet;
	Packet.Serialize(pStream);

	for (int32 i = 0; i < Packet.List.GetCurrentSize(); i++)
	{
		const auto &Data = Packet.List[i];
		UE_LOG(LogTemp, Log, TEXT("Player UUID:%d X:%f Y:%f"), Data.Uuid, Data.X, Data.Y);
	}
}
