#include "stdafx.h"
#include "AnpanAIStateBase.h"
#include "Character/Anpan/Anpan.h"
#include "Math/MathUtil.h"

// �R���X�g���N�^
AnpanAIStateBase::AnpanAIStateBase(Anpan *pInParent)
	: pParent(pInParent)
	, PrevPos(0.0f, 0.0f)
	, MoveTarget(0.0f, 0.0f)
	, MoveTime(0)
	, MoveStartTime(0)
	, PrevRotate(0.0f)
	, RotateTarget(0.0f)
	, RotateTime(0)
	, RotateStartTime(0)
{
}

// �f�X�g���N�^
AnpanAIStateBase::~AnpanAIStateBase()
{
}

// ���t���[���̏���.
void AnpanAIStateBase::Poll(int DeltaTime)
{
	Update(DeltaTime);
	UpdateMove(DeltaTime);
	UpdateRotate(DeltaTime);
}


// �ړ���ݒ�.
void AnpanAIStateBase::SetMove(const Vector2D &InMoveTarget, int Time)
{
	PrevPos = pParent->GetPosition();
	MoveTarget = InMoveTarget;
	MoveTime = Time;
	MoveStartTime = Time;
}

// ��]��ݒ�.
void AnpanAIStateBase::SetRotate(const Rotation &InRotateTarget, int Time)
{
	PrevRotate = pParent->GetRotation();
	RotateTarget = InRotateTarget;
	RotateTime = Time;
	RotateStartTime = Time;
}


// �ړ��X�V.
void AnpanAIStateBase::UpdateMove(int DeltaTime)
{
	if (MoveTime <= 0) { return; }

	MoveTime -= DeltaTime;
	if (MoveTime <= 0)
	{
		MoveTime = 0;
	}

	float Rate = (MoveTime / (float)MoveStartTime);
	Vector2D Pos = MathUtil::Lerp<Vector2D>(PrevPos, MoveTarget, Rate);
	pParent->SetPosition(Pos);
}

// ��]�X�V.
void AnpanAIStateBase::UpdateRotate(int DeltaTime)
{
	if (RotateTime <= 0) { return; }

	RotateTime -= DeltaTime;
	if (RotateTime <= 0)
	{
		RotateTime = 0;
	}

	float Rate = (RotateTime / (float)RotateStartTime);
	Rotation Rot = MathUtil::Lerp<Rotation>(PrevRotate, RotateTarget, Rate);
	pParent->SetRotate(Rot);
}
