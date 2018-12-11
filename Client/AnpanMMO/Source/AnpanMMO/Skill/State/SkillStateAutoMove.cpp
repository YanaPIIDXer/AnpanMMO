// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "SkillStateAutoMove.h"
#include "Skill/SkillControl.h"
#include "Character/CharacterBase.h"

// �R���X�g���N�^
SkillStateAutoMove::SkillStateAutoMove(SkillControl *pInControl)
	: SkillStateBase(pInControl)
	, pOwner(nullptr)
	, pTarget(nullptr)
	, Distance(0.0f)
{
}

// State�J�n���̏���.
void SkillStateAutoMove::BeginState()
{
	pOwner = GetControl()->GetOwner();
	pTarget = GetControl()->GetTarget();
	Distance = GetControl()->GetSkillData().Distance;
}

// ���t���[���̏���.
void SkillStateAutoMove::Poll()
{
	if (pTarget == nullptr) { return; }		// �^�[�Q�b�g���������B

	FVector TargetVec = (pTarget->GetActorLocation() - pOwner->GetActorLocation());
	TargetVec.Z = 0.0f;
	TargetVec.Normalize();

	if (TargetVec.SizeSquared() > Distance * Distance)
	{
		pOwner->AddMovementInput(TargetVec);
	}
}
