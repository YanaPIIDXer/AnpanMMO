// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "PlayerManager.h"
#include "Other/OtherPlayerCharacter.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "Packet/PacketSpawnPlayer.h"
#include "Packet/PacketPlayerList.h"
#include "Packet/PacketMovePlayer.h"
#include "Packet/PacketPlayerRespawn.h"
#include "Packet/PacketExitPlayer.h"
#include "Kismet/GameplayStatics.h"

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
	if (!PlayerMap.Contains(Uuid)) { return nullptr; }
	return PlayerMap[Uuid].Get();
}

// 生成を受信.
void PlayerManager::OnRecvSpawn(MemoryStreamInterface *pStream)
{
	PacketSpawnPlayer Packet;
	Packet.Serialize(pStream);

	SpawnCharacter(Packet.Uuid, Packet.X, Packet.Y, 0.0f, Packet.Hp, Packet.MaxHp);
}

// リストを受信.
void PlayerManager::OnRecvList(MemoryStreamInterface *pStream)
{
	PacketPlayerList Packet;
	Packet.Serialize(pStream);

	for (int32 i = 0; i < Packet.List.GetCurrentSize(); i++)
	{
		const auto &Data = Packet.List[i];
		SpawnCharacter(Data.Uuid, Data.X, Data.Y, Data.Rotation, Data.Hp, Data.MaxHp);
	}
}

// 移動を受信.
void PlayerManager::OnRecvMove(MemoryStreamInterface *pStream)
{
	PacketMovePlayer Packet;
	Packet.Serialize(pStream);

	PlayerMap[Packet.Uuid]->Move(Packet.X, Packet.Y, Packet.Rotation);
}

// リスポンを受信.
void PlayerManager::OnRecvRespawn(MemoryStreamInterface *pStream)
{
	PacketPlayerRespawn Packet;
	Packet.Serialize(pStream);

	auto *pPlayer = PlayerMap.Find(Packet.Uuid);
	check(pPlayer != nullptr);
	pPlayer->Get()->Respawn(Packet.X, Packet.Y);
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

// リセット.
void PlayerManager::Reset()
{
	TArray<uint32> RemoveList;
	for (auto KeyValue : PlayerMap)
	{
		// 自キャラは消さないようにする。
		if (KeyValue.Value == UGameplayStatics::GetPlayerPawn(KeyValue.Value.Get(), 0)) { continue; }
		KeyValue.Value->Destroy();
		RemoveList.Add(KeyValue.Key);
	}

	for (uint32 Id : RemoveList)
	{
		PlayerMap.Remove(Id);
	}
}


// キャラクタをSpawn
void PlayerManager::SpawnCharacter(uint32 Uuid, float X, float Y, float Rotation, int32 Hp, int32 MaxHp)
{
	auto *pCharacter = AOtherPlayerCharacter::Spawn(pWorld.Get(), FVector(X, Y, 110.0f), FRotator(0.0f, Rotation, 0.0f), Hp, MaxHp);
	PlayerMap.Add(Uuid, pCharacter);
}
