// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "AnpanManager.h"
#include "Anpan.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "Packet/PacketAnpanList.h"
#include "Packet/PacketSpawnAnpan.h"
#include "Packet/PacketMoveAnpan.h"
#include "Packet/PacketRotateAnpan.h"
#include "Packet/PacketStopAnpan.h"

// �R���X�g���N�^
AnpanManager::AnpanManager()
	: pWorld(nullptr)
{
}

// ���t���[���̏���.
void AnpanManager::Poll()
{
	for (auto It = AnpanMap.CreateIterator(); It; ++It)
	{
		if (!It->Value.IsValid())
		{
			AnpanMap.Remove(It.Key());
		}
	}
}

// �擾.
AAnpan *AnpanManager::Get(uint32 Uuid) const
{
	if (!AnpanMap.Contains(Uuid)) { return nullptr; }
	return AnpanMap[Uuid].Get();
}

// ���X�g����M����.
void AnpanManager::OnRecvList(MemoryStreamInterface *pStream)
{
	PacketAnpanList Packet;
	Packet.Serialize(pStream);

	const auto &List = Packet.List;
	for (int32 i = 0; i < List.GetCurrentSize(); i++)
	{
		const AnpanData &Data = List[i];
		SpawnAnpan(Data);
	}
}

// ��������M����.
void AnpanManager::OnRecvSpawn(MemoryStreamInterface *pStream)
{
	PacketSpawnAnpan Packet;
	Packet.Serialize(pStream);

	SpawnAnpan(Packet.Data);
}

// �ړ�����M�����B
void AnpanManager::OnRecvMove(MemoryStreamInterface *pStream)
{
	PacketMoveAnpan Packet;
	Packet.Serialize(pStream);

	if (!AnpanMap.Contains(Packet.Uuid)) { return; }
	AnpanMap[Packet.Uuid]->Move(Packet.X, Packet.Y, Packet.MoveMilliSec);
}

// ��]����M�����B
void AnpanManager::OnRecvRotate(MemoryStreamInterface *pStream)
{
	PacketRotateAnpan Packet;
	Packet.Serialize(pStream);

	if (!AnpanMap.Contains(Packet.Uuid)) { return; }
	AnpanMap[Packet.Uuid]->Rotate(Packet.Rotation, Packet.RotateMilliSec);
}

// ��~����M�����B
void AnpanManager::OnRecvStop(MemoryStreamInterface *pStream)
{
	PacketStopAnpan Packet;
	Packet.Serialize(pStream);

	if (!AnpanMap.Contains(Packet.Uuid)) { return; }
	AnpanMap[Packet.Uuid]->Stop(Packet.X, Packet.Y, Packet.Rotation);
}

// ���Z�b�g
void AnpanManager::Reset()
{
	for (auto KeyValue : AnpanMap)
	{
		KeyValue.Value->Destroy();
	}
	AnpanMap.Empty();
}


// �A���p����Spawn
void AnpanManager::SpawnAnpan(const AnpanData &Data)
{
	auto *pAnpan = AAnpan::Spawn(pWorld.Get(), Data);
	AnpanMap.Add(Data.Uuid, pAnpan);
}
