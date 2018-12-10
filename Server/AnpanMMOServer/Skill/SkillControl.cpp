#include "stdafx.h"
#include "SkillControl.h"
#include "Master/MasterData.h"
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
	if (OnCastFinishedFunc)
	{
		OnCastFinishedFunc();
	}

	const SkillItem *pItem = MasterData::GetInstance().GetSkillMaster().GetItem(SkillId);
	if (pItem->RangeType == SkillItem::NORMAL)
	{
		// �ʏ�X�L���Ȃ�I�[�g�ړ��ցB
		ChangeState(new SkillStateAutoMove(this));
	}
	else
	{
		// �����łȂ��Ȃ瑦�������B
		Activate();
	}
}

// �L�����Z��
void SkillControl::Cancel(u8 Reason)
{
	if (OnCancelFunc)
	{
		OnCancelFunc(Reason);
	}

	ChangeState(new SkillStateNutral(this));
}

// ����.
void SkillControl::Activate()
{
	if (OnActivateFunc)
	{
		OnActivateFunc();
	}

	// ������State��Nutral�ɖ߂��B
	ChangeState(new SkillStateNutral(this));
}

// ��������Ă��邩�H
bool SkillControl::IsActive() const
{
	return (pState->GetStateType() != Nutral);
}
