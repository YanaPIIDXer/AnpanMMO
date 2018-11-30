#include "stdafx.h"
#include "InstanceArea.h"
#include "Master/AreaMaster.h"

// �R���X�g���N�^
InstanceArea::InstanceArea(u32 InUuid, const AreaItem *pItem)
	: AreaBase(pItem)
	, Uuid(InUuid)
{
}

// �����\���H
bool InstanceArea::IsAbleDelete() const
{
	return (PlayerMgr.GetCount() == 0);
}
