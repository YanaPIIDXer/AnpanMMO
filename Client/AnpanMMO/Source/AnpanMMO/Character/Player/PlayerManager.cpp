// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "PlayerManager.h"
#include "Other/OtherPlayerCharacter.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "Packet/PacketSpawnPlayer.h"
#include "Packet/PacketPlayerList.h"
#include "Packet/PacketMovePlayer.h"
#include "Packet/PacketExitPlayer.h"

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

	SpawnCharacter(Packet.Uuid, 0.0f, 0.0f, 0.0f);
}

// リストを受信.
void PlayerManager::OnRecvList(MemoryStreamInterface *pStream)
{
	PacketPlayerList Packet;
	Packet.Serialize(pStream);

	for (int32 i = 0; i < Packet.List.GetCurrentSize(); i++)
	{
		const auto &Data = Packet.List[i];
		SpawnCharacter(Data.Uuid, Data.X, Data.Y, Data.Rotation);
	}
}

// 移動を受信.
void PlayerManager::OnRecvMove(MemoryStreamInterface *pStream)
{
	PacketMovePlayer Packet;
	Packet.Serialize(pStream);

	PlayerMap[Packet.Uuid]->Move(Packet.X, Packet.Y, Packet.Rotation);
}

// 退出を受信.
void PlayerManager::OnRecvExit(MemoryStreamInterface *pStream)
{
	PacketExitPlayer Packet;
	Packet.Serialize(pStream);

	auto *pPlayer = PlayerMap.Find(Packet.Uuid);
	check(pPlayer != nullptr);
	pPlayer->Get()->Destroy();
	PlayerMap.Remove(Packet.Uuid);
}


// キャラクタをSpawn
void PlayerManager::SpawnCharacter(uint32 Uuid, float X, float Y, float Rotation)
{
	auto *pCharacter = AOtherPlayerCharacter::Spawn(pWorld.Get(), FVector(X, Y, 110.0f), FRotator(0.0f, Rotation, 0.0f));
	PlayerMap.Add(Uuid, pCharacter);
}
