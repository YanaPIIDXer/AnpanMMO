// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#include "SkillControl.h"
#include "Master/MasterData.h"
#include "State/SkillStateNutral.h"
#include "State/SkillStateCast.h"
#include "State/SkillStateAutoMove.h"

// �R���X�g���N�^
SkillControl::SkillControl()
	: pState(new SkillStateNutral(this))
	, pPrevState(nullptr)
	, pOwner(nullptr)
	, pTarget(nullptr)
{
}

// �f�X�g���N�^
SkillControl::~SkillControl()
{
	delete pPrevState;
	delete pState;
}

// ���t���[���̏���.
void SkillControl::Poll()
{
	if (pPrevState != nullptr)
	{
		delete pPrevState;
		pPrevState = nullptr;
	}

	pState->Poll();
}

// �X�L���g�p.
void SkillControl::UseSkill(uint32 SkillId, ACharacterBase *pInTarget)
{
	SkillData = *MasterData::GetInstance().GetSkillMaster().Get(SkillId);
	pTarget = pInTarget;

	// �L���X�g�J�n.
	ChangeState(new SkillStateCast(this));
}

// �L���X�g�����������B
void SkillControl::OnCastFinished()
{
	ChangeState(new SkillStateAutoMove(this));
}

// �X�L�������������B
void SkillControl::OnActivate()
{
	// �j���[�g�����ɖ߂��B
	ChangeState(new SkillStateNutral(this));
}

// �L�����Z�����ꂽ
void SkillControl::OnCancel()
{
	// �j���[�g�����ɖ߂��B
	ChangeState(new SkillStateNutral(this));
}

// �������Ă��邩�H
bool SkillControl::IsActive() const
{
	return (pState->GetStateType() != ESkillStateType::Nutral);
}


// State�؂�ւ�
void SkillControl::ChangeState(SkillStateBase *pNewState)
{
	pPrevState = pState;
	pState = pNewState;
	pState->BeginState();
}
