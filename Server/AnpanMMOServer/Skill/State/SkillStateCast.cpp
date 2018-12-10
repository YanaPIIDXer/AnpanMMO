#include "stdafx.h"
#include "SkillStateCast.h"
#include "Master/MasterData.h"
#include "Skill/SkillControl.h"

// コンストラクタ
SkillStateCast::SkillStateCast(SkillControl *pInControl)
	: SkillStateBase(pInControl)
{
	const SkillItem *pItem = MasterData::GetInstance().GetSkillMaster().GetItem(pInControl->GetSkillId());
	CastTime = pItem->CastTime * 1000;
}

// 毎フレームの処理.
void SkillStateCast::Poll(s32 DeltaTime)
{
	CastTime -= DeltaTime;
	if (CastTime <= 0)
	{
		GetControl()->CastFinished();
	}
}
