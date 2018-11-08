// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "AnpanManager.h"
#include "Anpan.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "Packet/PacketAnpanList.h"
#include "Packet/PacketSpawnAnpan.h"
#include "Packet/PacketMoveAnpan.h"
#include "Packet/PacketRotateAnpan.h"

// コンストラクタ
AnpanManager::AnpanManager()
	: pWorld(nullptr)
{
}

// 毎フレームの処理.
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

// 取得.
AAnpan *AnpanManager::Get(uint32 Uuid) const
{
	if (!AnpanMap.Contains(Uuid)) { return nullptr; }
	return AnpanMap[Uuid].Get();
}

// リストを受信した.
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

// 生成を受信した.
void AnpanManager::OnRecvSpawn(MemoryStreamInterface *pStream)
{
	PacketSpawnAnpan Packet;
	Packet.Serialize(pStream);

	SpawnAnpan(Packet.Data);
}

// 移動を受信した。
void AnpanManager::OnRecvMove(MemoryStreamInterface *pStream)
{
	PacketMoveAnpan Packet;
	Packet.Serialize(pStream);

	AnpanMap[Packet.Uuid]->Move(Packet.X, Packet.Y, Packet.MoveMilliSec);
}

// 回転を受信した。
void AnpanManager::OnRecvRotate(MemoryStreamInterface *pStream)
{
	PacketRotateAnpan Packet;
	Packet.Serialize(pStream);

	AnpanMap[Packet.Uuid]->Rotate(Packet.Rotation, Packet.RotateMilliSec);
}


// アンパンをSpawn
void AnpanManager::SpawnAnpan(const AnpanData &Data)
{
	auto *pAnpan = AAnpan::Spawn(pWorld.Get(), Data);
	AnpanMap.Add(Data.Uuid, pAnpan);
}
