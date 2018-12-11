// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "SkillStateAutoMove.h"
#include "Skill/SkillControl.h"
#include "Character/CharacterBase.h"

// コンストラクタ
SkillStateAutoMove::SkillStateAutoMove(SkillControl *pInControl)
	: SkillStateBase(pInControl)
	, pOwner(nullptr)
	, pTarget(nullptr)
	, Distance(0.0f)
{
}

// State開始時の処理.
void SkillStateAutoMove::BeginState()
{
	pOwner = GetControl()->GetOwner();
	pTarget = GetControl()->GetTarget();
	Distance = GetControl()->GetSkillData().Distance;
}

// 毎フレームの処理.
void SkillStateAutoMove::Poll()
{
	if (pTarget == nullptr) { return; }		// ターゲットが消えた。

	FVector TargetVec = (pTarget->GetActorLocation() - pOwner->GetActorLocation());
	TargetVec.Z = 0.0f;
	TargetVec.Normalize();

	if (TargetVec.SizeSquared() > Distance * Distance)
	{
		pOwner->AddMovementInput(TargetVec);
	}
}
