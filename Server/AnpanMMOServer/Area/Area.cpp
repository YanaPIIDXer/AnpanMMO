#include "stdafx.h"
#include "Area.h"
#include "Master/AreaMaster.h"

// コンストラクタ
Area::Area(const AreaItem *pInItem)
	: pItem(pInItem)
{
}

// 毎フレームの処理.
void Area::Poll(int DeltaTime)
{
}
