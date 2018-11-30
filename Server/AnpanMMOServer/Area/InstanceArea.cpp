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
{
}

// ������.
void InstanceArea::Initialize()
{
	const InstanceInfoItem *pInstanceInfoItem = MasterData::GetInstance().GetInstanceInfoMaster().GetItem(InfoMasterId);
	Vector3D BossPosition(pInstanceInfoItem->BossX, pInstanceInfoItem->BossY, pInstanceInfoItem->BossZ);
	AnpanMgr.Spawn(pInstanceInfoItem->BossId, BossPosition);
	ExitWarpDataId = pInstanceInfoItem->ExitWarpDataId;
}

// �����\���H
bool InstanceArea::IsAbleDelete() const
{
	return (PlayerMgr.GetCount() == 0);
}


// �X�V.
void InstanceArea::Update()
{
	if (!bSpawnedExitPoint && AnpanMgr.GetCount() == 0)
	{
		// �{�X�����񂾂�E�o�|�C���g�𐶐�.
		PacketSpawnInstanceAreaExitPoint Packet(ExitWarpDataId);
		BroadcastPacket(&Packet);
		bSpawnedExitPoint = true;
	}
}
