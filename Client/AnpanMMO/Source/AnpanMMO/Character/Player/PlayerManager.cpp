// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "PlayerManager.h"
#include "Other/OtherPlayerCharacter.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "Packet/PacketSpawnPlayer.h"
#include "Packet/PacketPlayerList.h"
#include "Packet/PacketMovePlayer.h"
#include "Packet/PacketExitPlayer.h"
#include "Kismet/GameplayStatics.h"

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
	if (!PlayerMap.Contains(Uuid)) { return nullptr; }
	return PlayerMap[Uuid].Get();
}

// ��������M.
void PlayerManager::OnRecvSpawn(MemoryStreamInterface *pStream)
{
	PacketSpawnPlayer Packet;
	Packet.Serialize(pStream);

	SpawnCharacter(Packet.Uuid, Packet.X, Packet.Y, Packet.Z, 0.0f, Packet.Hp, Packet.MaxHp);
}

// ���X�g����M.
void PlayerManager::OnRecvList(MemoryStreamInterface *pStream)
{
	PacketPlayerList Packet;
	Packet.Serialize(pStream);

	for (int32 i = 0; i < Packet.List.GetCurrentSize(); i++)
	{
		const auto &Data = Packet.List[i];
		SpawnCharacter(Data.Uuid, Data.X, Data.Y, Data.Z, Data.Rotation, Data.Hp, Data.MaxHp);
	}
}

// �ړ�����M.
void PlayerManager::OnRecvMove(MemoryStreamInterface *pStream)
{
	PacketMovePlayer Packet;
	Packet.Serialize(pStream);

	PlayerMap[Packet.Uuid]->Move(Packet.X, Packet.Y, Packet.Z, Packet.Rotation);
}

// �ޏo����M.
void PlayerManager::OnRecvExit(MemoryStreamInterface *pStream)
{
	PacketExitPlayer Packet;
	Packet.Serialize(pStream);

	auto *pPlayer = PlayerMap.Find(Packet.Uuid);
	check(pPlayer != nullptr);
	pPlayer->Get()->Destroy();
	PlayerMap.Remove(Packet.Uuid);
}

// ���Z�b�g.
void PlayerManager::Reset()
{
	TArray<uint32> RemoveList;
	for (auto KeyValue : PlayerMap)
	{
		// ���L�����͏����Ȃ��悤�ɂ���B
		if (KeyValue.Value == UGameplayStatics::GetPlayerPawn(KeyValue.Value.Get(), 0)) { continue; }
		KeyValue.Value->Destroy();
		RemoveList.Add(KeyValue.Key);
	}

	for (uint32 Id : RemoveList)
	{
		PlayerMap.Remove(Id);
	}
}


// �L�����N�^��Spawn
void PlayerManager::SpawnCharacter(uint32 Uuid, float X, float Y, float Z, float Rotation, int32 Hp, int32 MaxHp)
{
	auto *pCharacter = AOtherPlayerCharacter::Spawn(pWorld.Get(), FVector(X, Y, Z), FRotator(0.0f, Rotation, 0.0f), Hp, MaxHp);
	check(pCharacter != nullptr);
	PlayerMap.Add(Uuid, pCharacter);
}
