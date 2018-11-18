#include "stdafx.h"
#include "AnpanAIStateActive.h"
#include "Character/Anpan/AI/AnpanAI.h"
#include "AnpanAIStateNonActive.h"
#include "Character/CharacterBase.h"
#include "Character/Anpan/Anpan.h"
#include "Math/MathUtil.h"
#include <math.h>

const float AnpanAIStateActive::ApproachDist = 200.0f;
const int AnpanAIStateActive::AttackInterval = 5000;

// コンストラクタ
AnpanAIStateActive::AnpanAIStateActive(Anpan *pInParent)
	: AnpanAIStateBase(pInParent)
	, AttackTimer(0)
{
	pCurrentTarget.reset();
}


// 更新.
void AnpanAIStateActive::Update(int DeltaTime)
{
	weak_ptr<CharacterBase> pChara = GetAI()->GetHate().GetTop();
	if (pChara.expired())
	{
		// ヘイトリストからキャラがいなくなった。
		GetAI()->ChangeState(new AnpanAIStateNonActive(GetParent()));
		return;
	}

	if (pCurrentTarget.expired() || pChara.lock().get() != pCurrentTarget.lock().get())
	{
		pCurrentTarget = pChara;
	}

	UpdateMove();
	UpdateRotate();
	UpdateAttack(DeltaTime);
}


// 回転を更新.
void AnpanAIStateActive::UpdateRotate()
{
	if (!IsRotating())
	{
		RotateToTarget();
	}
}

// 移動を更新.
void AnpanAIStateActive::UpdateMove()
{
	if (!IsMoving())
	{
		MoveToTarget();
	}

	if (IsApproached())
	{
		Stop();
	}
}

// 攻撃を更新.
void AnpanAIStateActive::UpdateAttack(int DeltaTime)
{
	AttackTimer -= DeltaTime;
	if (AttackTimer <= 0)
	{
		AttackTimer = 0;
		if (!IsApproached()) { return; }
		
		GetParent()->AttackTo(pCurrentTarget.lock().get());
		AttackTimer += AttackInterval;
	}
}

// ターゲットの方向を向く。
void AnpanAIStateActive::RotateToTarget()
{
	Vector3D TargetVec = (pCurrentTarget.lock()->GetPosition() - GetParent()->GetPosition()).GetNormalized();
	Vector3D CenterVec = GetParent()->GetCenterVec();

	float Dot = MathUtil::Dot(TargetVec, CenterVec);
	float Rad = acos(Dot);
	float Deg = MathUtil::RadToDeg(Rad);

	if (isnan(Deg))
	{
		Deg = 0.0f;
	}

	if (MathUtil::Cross(CenterVec, TargetVec).X < 0.0f)
	{
		Deg *= -1.0f;
	}
	
	SetRotate(Rotation(Deg), 300);
}

// ターゲットに向かって移動する。
void AnpanAIStateActive::MoveToTarget()
{
	if (IsApproached()) { return; }

	Vector3D TargetVec = (pCurrentTarget.lock()->GetPosition() - GetParent()->GetPosition());
	float Size = TargetVec.GetSize();
	TargetVec.Normalize();
	TargetVec *= (Size - ApproachDist);
	
	SetMove(TargetVec, 1000);
}

// 接近しているか？
bool AnpanAIStateActive::IsApproached()
{
	Vector3D TargetVec = pCurrentTarget.lock()->GetPosition() - GetParent()->GetPosition();
	return (TargetVec.GetSizeSq() < ApproachDist * ApproachDist);
}
