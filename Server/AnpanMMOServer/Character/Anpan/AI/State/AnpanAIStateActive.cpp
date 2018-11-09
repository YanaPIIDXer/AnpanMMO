#include "stdafx.h"
#include "AnpanAIStateActive.h"
#include "Character/Anpan/AI/AnpanAI.h"
#include "AnpanAIStateNonActive.h"
#include "Character/CharacterBase.h"
#include "Character/Anpan/Anpan.h"
#include "Math/MathUtil.h"
#include <math.h>

const float AnpanAIStateActive::ApproachDist = 200.0f;

// �R���X�g���N�^
AnpanAIStateActive::AnpanAIStateActive(Anpan *pInParent)
	: AnpanAIStateBase(pInParent)
	, MoveTimer(0)
	, RotateTimer(0)
{
	pCurrentTarget.reset();
}


// �X�V.
void AnpanAIStateActive::Update(int DeltaTime)
{
	weak_ptr<CharacterBase> pChara = GetAI()->GetHate().GetTop();
	if (pChara.expired())
	{
		// �w�C�g���X�g����L���������Ȃ��Ȃ����B
		GetAI()->ChangeState(new AnpanAIStateNonActive(GetParent()));
		return;
	}

	if (pCurrentTarget.expired() || pChara.lock().get() != pCurrentTarget.lock().get())
	{
		pCurrentTarget = pChara;
	}

	UpdateMove(DeltaTime);
	UpdateRotate(DeltaTime);
}


// ��]���X�V.
void AnpanAIStateActive::UpdateRotate(int DeltaTime)
{
	RotateTimer -= DeltaTime;
	if (RotateTimer <= 0)
	{
		RotateToTarget();
	}
}

// �ړ����X�V.
void AnpanAIStateActive::UpdateMove(int DeltaTime)
{
	MoveTimer -= DeltaTime;
	if (MoveTimer <= 0)
	{
		MoveToTarget();
	}

	if (IsApproached())
	{
		Stop();
		MoveTimer = 0;
	}
}

// �^�[�Q�b�g�̕����������B
void AnpanAIStateActive::RotateToTarget()
{
	Vector2D TargetVec = (pCurrentTarget.lock()->GetPosition() - GetParent()->GetPosition()).GetNormalized();
	Vector2D CenterVec = GetParent()->GetCenterVec();

	float Dot = MathUtil::Dot(TargetVec, CenterVec);
	float Rad = acos(Dot);
	float Deg = MathUtil::RadToDeg(Rad);

	RotateTimer = 300;
	SetRotate(Rotation(Deg), RotateTimer);
}

// �^�[�Q�b�g�Ɍ������Ĉړ�����B
void AnpanAIStateActive::MoveToTarget()
{
	if (IsApproached()) { return; }

	Vector2D TargetVec = (pCurrentTarget.lock()->GetPosition() - GetParent()->GetPosition());
	float Size = TargetVec.GetSize();
	TargetVec.Normalize();
	TargetVec *= (Size - ApproachDist);
	
	MoveTimer = 1000;
	SetMove(TargetVec, MoveTimer);
}

// �ڋ߂��Ă��邩�H
bool AnpanAIStateActive::IsApproached()
{
	Vector2D TargetVec = pCurrentTarget.lock()->GetPosition() - GetParent()->GetPosition();
	return (TargetVec.GetSizeSq() < ApproachDist * ApproachDist);
}
