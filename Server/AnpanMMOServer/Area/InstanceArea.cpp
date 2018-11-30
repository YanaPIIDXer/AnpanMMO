#include "stdafx.h"
#include "InstanceArea.h"
#include "Master/AreaMaster.h"

// コンストラクタ
InstanceArea::InstanceArea(u32 InUuid, const AreaItem *pItem)
	: AreaBase(pItem)
	, Uuid(InUuid)
{
}

// 消去可能か？
bool InstanceArea::IsAbleDelete() const
{
	return (PlayerMgr.GetCount() == 0);
}
