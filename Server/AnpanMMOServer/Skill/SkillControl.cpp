#include "stdafx.h"
#include "SkillControl.h"
#include "State/SkillStateNutral.h"

// コンストラクタ
SkillControl::SkillControl(CharacterBase *pInOwner)
	: pState(new SkillStateNutral(this))
	, pOwner(pInOwner)
	, pTarget(NULL)
	, SkillId(0)
{
}

// 毎フレームの処理.
void SkillControl::Poll(s32 DeltaTime)
{
	pState->Poll(DeltaTime);
}

// 使用.
void SkillControl::Use(u32 InSkillId, CharacterBase *pInTarget)
{
	SkillId = InSkillId;
	pTarget = pInTarget;
}
