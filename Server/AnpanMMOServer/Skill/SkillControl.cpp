#include "stdafx.h"
#include "SkillControl.h"
#include "State/SkillStateNutral.h"
#include "State/SkillStateCast.h"
#include "State/SkillStateAutoMove.h"

// �R���X�g���N�^
SkillControl::SkillControl(CharacterBase *pInOwner)
	: pState(new SkillStateNutral(this))
	, pPrevState(NULL)
	, pOwner(pInOwner)
	, pTarget(NULL)
	, SkillId(0)
{
}

// ���t���[���̏���.
void SkillControl::Poll(s32 DeltaTime)
{
	if (pPrevState != NULL)
	{
		delete pPrevState;
		pPrevState = NULL;
	}

	pState->Poll(DeltaTime);
}

// �g�p.
void SkillControl::Use(u32 InSkillId, CharacterBase *pInTarget)
{
	SkillId = InSkillId;
	pTarget = pInTarget;
	ChangeState(new SkillStateCast(this));
}

// �X�e�[�g�ύX.
void SkillControl::ChangeState(SkillStateBase *pNewState)
{
	pPrevState = pState;
	pState = pNewState;
}

// �L���X�g�����������B
void SkillControl::CastFinished()
{
	ChangeState(new SkillStateAutoMove(this));
	if (OnCastFinishedFunc)
	{
		OnCastFinishedFunc();
	}
}

// �L�����Z��
void SkillControl::Cancel(u8 Reason)
{
	ChangeState(new SkillStateNutral(this));
	if (OnCancelFunc)
	{
		OnCancelFunc(Reason);
	}
}

// ����.
void SkillControl::Activate()
{
	// ������State��Nutral�ɖ߂��B
	ChangeState(new SkillStateNutral(this));
	if (OnActivateFunc)
	{
		OnActivateFunc();
	}
}
