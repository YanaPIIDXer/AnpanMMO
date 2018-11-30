#include "stdafx.h"
#include "AnpanAIStateBase.h"
#include "Character/Anpan/Anpan.h"
#include "Math/MathUtil.h"
#include "Area/AreaBase.h"

// コンストラクタ
AnpanAIStateBase::AnpanAIStateBase(Anpan *pInParent)
	: pParent(pInParent)
	, PrevPos(0.0f, 0.0f, 0.0f)
	, MoveTarget(0.0f, 0.0f, 0.0f)
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
void AnpanAIStateBase::SetMove(const Vector3D &InMoveTarget, int Time)
{
	PrevPos = pParent->GetPosition();
	Vector3D StartPos = PrevPos;
	Vector3D EndPos = InMoveTarget + PrevPos;

	AreaPtr pArea = GetParent()->GetArea();
	pArea.lock()->CheckMovable(StartPos, EndPos, GetParent()->GetRadius(), MoveTarget);
	
	MoveTime = Time;
	MoveStartTime = Time;
	pAI->CreateMovePacketData(MoveTarget, MoveTime);
}

// 回転を設定.
void AnpanAIStateBase::SetRotate(const Rotation &InRotateTarget, int Time)
{
	PrevRotate = pParent->GetRotation();
	RotateTarget = InRotateTarget + PrevRotate.Get();
	RotateTime = Time;
	RotateStartTime = Time;
	pAI->CreateRotatePacketData(RotateTarget, RotateTime);
}

// 停止.
void AnpanAIStateBase::Stop()
{
	MoveTime = 0;
	RotateTime = 0;
	pAI->SetSendStopPacket();
}


// 移動更新.
void AnpanAIStateBase::UpdateMove(int DeltaTime)
{
	if (MoveTime <= 0) { return; }

	MoveTime -= DeltaTime;
	if (MoveTime <= 0)
	{
		MoveTime = 0;
		pParent->SetPosition(MoveTarget);
		return;
	}

	float Rate = 1.0f - (MoveTime / (float)MoveStartTime);
	Vector3D Pos = MathUtil::Lerp<Vector3D>(PrevPos, MoveTarget, Rate);

	AreaPtr pArea = GetParent()->GetArea();
	Pos.Z = pArea.lock()->GetHeight(Pos.X, Pos.Y);

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
		Rotation Rot(RotateTarget);
		pParent->SetRotate(Rot);
		return;
	}

	float Rate = 1.0f - (RotateTime / (float)RotateStartTime);
	Rotation Rot = MathUtil::Lerp<Rotation>(PrevRotate, RotateTarget, Rate);
	pParent->SetRotate(Rot);
}
