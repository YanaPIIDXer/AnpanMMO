#include "stdafx.h"
#include "Area.h"
#include "Master/AreaMaster.h"

// �R���X�g���N�^
Area::Area(const AreaItem *pItem)
	: AreaBase(pItem)
	, Id(pItem->ID)
{
}
