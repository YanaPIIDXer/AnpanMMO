// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#include "AnpanManager.h"
#include "Anpan.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "Kismet/GameplayStatics.h"
#include "Packet/PacketAnpanList.h"
#include "Packet/PacketSpawnAnpan.h"
#include "Packet/PacketMoveAnpan.h"
#include "Packet/PacketRotateAnpan.h"
#include "Packet/PacketStopAnpan.h"

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
bool AnpanManager::OnRecvList(MemoryStreamInterface *pStream)
{
	PacketAnpanList Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	const auto &List = Packet.List;
	for (int32 i = 0; i < List.GetCurrentSize(); i++)
	{
		const AnpanData &Data = List[i];
		SpawnAnpan(Data);
	}
	
	return true;
}

// 生成を受信した.
bool AnpanManager::OnRecvSpawn(MemoryStreamInterface *pStream)
{
	PacketSpawnAnpan Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	SpawnAnpan(Packet.Data);

	return true;
}

// 移動を受信した。
bool AnpanManager::OnRecvMove(MemoryStreamInterface *pStream)
{
	PacketMoveAnpan Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	if (!AnpanMap.Contains(Packet.Uuid)) { return true; }
	AnpanMap[Packet.Uuid]->Move(Packet.X, Packet.Y, Packet.Z, Packet.MoveMilliSec);

	return true;
}

// 回転を受信した。
bool AnpanManager::OnRecvRotate(MemoryStreamInterface *pStream)
{
	PacketRotateAnpan Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	if (!AnpanMap.Contains(Packet.Uuid)) { return true; }
	AnpanMap[Packet.Uuid]->Rotate(Packet.Rotation, Packet.RotateMilliSec);

	return true;
}

// 停止を受信した。
bool AnpanManager::OnRecvStop(MemoryStreamInterface *pStream)
{
	PacketStopAnpan Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	if (!AnpanMap.Contains(Packet.Uuid)) { return true; }
	AnpanMap[Packet.Uuid]->Stop(Packet.X, Packet.Y, Packet.Z, Packet.Rotation);

	return true;
}

// 前方のターゲットを取得.
AAnpan *AnpanManager::FindCenterTarget(float Distance)
{
	AAnpan *pTarget = nullptr;
	ACharacter *pCharacter = UGameplayStatics::GetPlayerCharacter(pWorld.Get(), 0);
	FVector CharacterPos = pCharacter->GetActorLocation();
	FVector CharacterCenter = pCharacter->GetActorForwardVector();
	float MinDist = FLT_MAX;
	for (auto KeyValue : AnpanMap)
	{
		AAnpan *pAnpan = KeyValue.Value.Get();
		if (pAnpan == nullptr) { continue; }		// 何故かnullptrを返すケースがあるらしい。
		FVector Dist = (pAnpan->GetActorLocation() - CharacterPos);
		Dist.Z = 0.0f;
		if (Dist.SizeSquared() > Distance * Distance) { continue; }
		float Dot = FVector::DotProduct(CharacterCenter, Dist.GetSafeNormal());
		float Angle = FMath::Acos(Dot);
		if (Angle > 45.0f) { continue; }
		if (Dist.SizeSquared() > MinDist) { continue; }
		pTarget = pAnpan;
		MinDist = Dist.SizeSquared();
	}

	return pTarget;
}

// リセット
void AnpanManager::Reset()
{
	for (auto KeyValue : AnpanMap)
	{
		KeyValue.Value->Destroy();
	}
	AnpanMap.Empty();
}


// アンパンをSpawn
void AnpanManager::SpawnAnpan(const AnpanData &Data)
{
	auto *pAnpan = AAnpan::Spawn(pWorld.Get(), Data);
	AnpanMap.Add(Data.Uuid, pAnpan);
}
