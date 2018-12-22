/**
 * @file InstanceArea.cpp
 * @brief インスタンスエリアクラス
 * @author YanaP
 */
#include "stdafx.h"
#include "InstanceArea.h"
#include "Master/AreaMaster.h"
#include "Master/MasterData.h"
#include "Packet/PacketSpawnInstanceAreaExitPoint.h"

// コンストラクタ
InstanceArea::InstanceArea(u32 InUuid, const AreaItem *pItem)
	: AreaBase(pItem)
	, Uuid(InUuid)
	, InfoMasterId(pItem->InstanceInfoId)
	, bSpawnedExitPoint(false)
	, ExitWarpPointId(0)
	, bInitialized(false)
{
}

// 初期化.
void InstanceArea::Initialize()
{
	const InstanceInfoItem *pInstanceInfoItem = MasterData::GetInstance().GetInstanceInfoMaster().GetItem(InfoMasterId);
	Vector3D BossPosition(pInstanceInfoItem->BossX, pInstanceInfoItem->BossY, pInstanceInfoItem->BossZ);
	AnpanMgr.Spawn(pInstanceInfoItem->BossId, BossPosition);
	ExitWarpPointId = pInstanceInfoItem->ExitWarpPointId;
}

// 消去可能か？
bool InstanceArea::IsAbleDelete() const
{
	return (bInitialized && PlayerMgr.GetCount() == 0);
}


// 更新.
void InstanceArea::Update()
{
	if (!bSpawnedExitPoint && AnpanMgr.GetCount() == 0)
	{
		// ボスが死んだら脱出ポイントを生成.
		PacketSpawnInstanceAreaExitPoint Packet(ExitWarpPointId);
		BroadcastPacket(&Packet);
		bSpawnedExitPoint = true;
	}
	if (!bInitialized && PlayerMgr.GetCount() > 0)
	{
		bInitialized = true;
	}
}
