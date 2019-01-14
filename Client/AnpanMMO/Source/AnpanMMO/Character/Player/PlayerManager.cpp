// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#include "PlayerManager.h"
#include "Other/OtherPlayerCharacter.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "Packet/PacketSpawnPlayer.h"
#include "Packet/PacketPlayerList.h"
#include "Packet/PacketMovePlayer.h"
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
bool PlayerManager::OnRecvSpawn(MemoryStreamInterface *pStream)
{
	PacketSpawnPlayer Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	SpawnCharacter(Packet.Data);

	return true;
}

// リストを受信.
bool PlayerManager::OnRecvList(MemoryStreamInterface *pStream)
{
	PacketPlayerList Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	for (int32 i = 0; i < Packet.List.GetCurrentSize(); i++)
	{
		const auto &Data = Packet.List[i];
		SpawnCharacter(Data);
	}

	return true;
}

// 移動を受信.
bool PlayerManager::OnRecvMove(MemoryStreamInterface *pStream)
{
	PacketMovePlayer Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	PlayerMap[Packet.Uuid]->Move(Packet.X, Packet.Y, Packet.Z, Packet.Rotation);

	return true;
}

// 退出を受信.
bool PlayerManager::OnRecvExit(MemoryStreamInterface *pStream)
{
	PacketExitPlayer Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	auto *pPlayer = PlayerMap.Find(Packet.Uuid);
	check(pPlayer != nullptr);
	pPlayer->Get()->Destroy();
	PlayerMap.Remove(Packet.Uuid);

	return true;
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
void PlayerManager::SpawnCharacter(const PlayerData &Data)
{
	FString CharacterName = UTF8_TO_TCHAR(Data.Name.c_str());
	auto *pCharacter = AOtherPlayerCharacter::Spawn(pWorld.Get(), Data.Uuid, FVector(Data.X, Data.Y, Data.Z), FRotator(0.0f, Data.Rotation, 0.0f), Data.Hp, Data.MaxHp, CharacterName, Data.Job);
	check(pCharacter != nullptr);
	PlayerMap.Add(Data.Uuid, pCharacter);
}
