/**
 * @file Area.cpp
 * @brief エリアクラス
 * @author YanaP
 */
#include "stdafx.h"
#include "Area.h"
#include "Master/AreaMaster.h"

// コンストラクタ
Area::Area(const AreaItem *pItem)
	: AreaBase(pItem)
	, Id(pItem->ID)
{
}
