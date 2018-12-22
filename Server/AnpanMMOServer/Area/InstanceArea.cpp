/**
 * @file InstanceArea.cpp
 * @brief �C���X�^���X�G���A�N���X
 * @author YanaP
 */
#include "stdafx.h"
#include "InstanceArea.h"
#include "Master/AreaMaster.h"
#include "Master/MasterData.h"
#include "Packet/PacketSpawnInstanceAreaExitPoint.h"

// �R���X�g���N�^
InstanceArea::InstanceArea(u32 InUuid, const AreaItem *pItem)
	: AreaBase(pItem)
	, Uuid(InUuid)
	, InfoMasterId(pItem->InstanceInfoId)
	, bSpawnedExitPoint(false)
	, ExitWarpPointId(0)
	, bInitialized(false)
{
}

// ������.
void InstanceArea::Initialize()
{
	const InstanceInfoItem *pInstanceInfoItem = MasterData::GetInstance().GetInstanceInfoMaster().GetItem(InfoMasterId);
	Vector3D BossPosition(pInstanceInfoItem->BossX, pInstanceInfoItem->BossY, pInstanceInfoItem->BossZ);
	AnpanMgr.Spawn(pInstanceInfoItem->BossId, BossPosition);
	ExitWarpPointId = pInstanceInfoItem->ExitWarpPointId;
}

// �����\���H
bool InstanceArea::IsAbleDelete() const
{
	return (bInitialized && PlayerMgr.GetCount() == 0);
}


// �X�V.
void InstanceArea::Update()
{
	if (!bSpawnedExitPoint && AnpanMgr.GetCount() == 0)
	{
		// �{�X�����񂾂�E�o�|�C���g�𐶐�.
		PacketSpawnInstanceAreaExitPoint Packet(ExitWarpPointId);
		BroadcastPacket(&Packet);
		bSpawnedExitPoint = true;
	}
	if (!bInitialized && PlayerMgr.GetCount() > 0)
	{
		bInitialized = true;
	}
}
