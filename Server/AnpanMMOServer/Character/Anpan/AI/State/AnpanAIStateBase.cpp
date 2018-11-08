#include "stdafx.h"
#include "AnpanAIStateBase.h"
#include "Character/Anpan/Anpan.h"
#include "Math/MathUtil.h"

// コンストラクタ
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

// デストラクタ
AnpanAIStateBase::~AnpanAIStateBase()
{
}

// 毎フレームの処理.
void AnpanAIStateBase::Poll(int DeltaTime)
{
	Update(DeltaTime);
	UpdateMove(DeltaTime);
	UpdateRotate(DeltaTime);
}


// 移動を設定.
void AnpanAIStateBase::SetMove(const Vector2D &InMoveTarget, int Time)
{
	PrevPos = pParent->GetPosition();
	MoveTarget = InMoveTarget;
	MoveTime = Time;
	MoveStartTime = Time;
}

// 回転を設定.
void AnpanAIStateBase::SetRotate(const Rotation &InRotateTarget, int Time)
{
	PrevRotate = pParent->GetRotation();
	RotateTarget = InRotateTarget;
	RotateTime = Time;
	RotateStartTime = Time;
}


// 移動更新.
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

// 回転更新.
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
