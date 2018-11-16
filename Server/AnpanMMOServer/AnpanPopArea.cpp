#include "stdafx.h"
#include "AnpanPopArea.h"
#include "Master/AnpanPopAreaMaster.h"

// �R���X�g���N�^
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

// ���t���[���̏���.
void AnpanPopArea::Poll(int DeltaTime)
{
	CurrentInterval -= DeltaTime;
	if (CurrentInterval <= 0)
	{
		// @TODO:�A���p����Spawn���鏈���B
		CurrentInterval += PopInterval;
	}
}
