#include "stdafx.h"
#include "AnpanPopArea.h"
#include "Master/AnpanPopAreaMaster.h"

// コンストラクタ
AnpanPopArea::AnpanPopArea(const AnpanPopAreaItem *pMasterItem)
	: Range(pMasterItem->Range)
	, Position(pMasterItem->X, pMasterItem->Y)
	, MinHp(pMasterItem->MinHp)
	, MaxHp(pMasterItem->MaxHp)
	, MinAtk(pMasterItem->MinAtk)
	, MaxAtk(pMasterItem->MaxAtk)
	, MinDef(pMasterItem->MinDef)
	, MaxDef(pMasterItem->MaxDef)
	, MinExp(pMasterItem->MinDef)
	, MaxExp(pMasterItem->MaxDef)
	, PopInterval(pMasterItem->PopInterval)
	, CurrentInterval(pMasterItem->PopInterval)
{
}

// 毎フレームの処理.
void AnpanPopArea::Poll(int DeltaTime)
{
	CurrentInterval -= DeltaTime;
	if (CurrentInterval <= 0)
	{
		// @TODO:アンパンをSpawnする処理。
		CurrentInterval += PopInterval;
	}
}
