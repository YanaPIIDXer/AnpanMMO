#include "stdafx.h"
#include "SkillControl.h"
#include "State/SkillStateNutral.h"

// �R���X�g���N�^
SkillControl::SkillControl(CharacterBase *pInOwner)
	: pState(new SkillStateNutral(this))
	, pOwner(pInOwner)
	, pTarget(NULL)
	, SkillId(0)
{
}

// ���t���[���̏���.
void SkillControl::Poll(s32 DeltaTime)
{
	pState->Poll(DeltaTime);
}

// �g�p.
void SkillControl::Use(u32 InSkillId, CharacterBase *pInTarget)
{
	SkillId = InSkillId;
	pTarget = pInTarget;
}
