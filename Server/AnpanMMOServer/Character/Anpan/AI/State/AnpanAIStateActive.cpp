#include "stdafx.h"
#include "AnpanAIStateActive.h"
#include "Character/Anpan/AI/AnpanAI.h"
#include "AnpanAIStateNonActive.h"
#include "Character/CharacterBase.h"
#include "Character/Anpan/Anpan.h"
#include "Math/MathUtil.h"

// コンストラクタ
AnpanAIStateActive::AnpanAIStateActive(Anpan *pInParent)
	: AnpanAIStateBase(pInParent)
	, ActionTimer(0)
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

	ActionTimer -= DeltaTime;
	if (ActionTimer <= 0)
	{
		Vector2D TargetPosition = pCurrentTarget.lock()->GetPosition();
		Vector2D MyPosition = GetParent()->GetPosition();
		if ((TargetPosition - MyPosition).GetSizeSq() < 500.0f * 500.0f) { return; }
		Vector2D MoveVec = (TargetPosition - MyPosition).GetNormalized();
		float Dot = MoveVec.Dot(GetParent()->GetCenterVec());
		float Angle = MathUtil::RadToDeg(Dot);
		Angle += GetParent()->GetRotation().Get();
		MoveVec *= 1000.0f;
		ActionTimer = 1000;
		SetMove(MyPosition + MoveVec, ActionTimer);
		SetRotate(Rotation(Angle), ActionTimer);
	}
	else
	{
		Vector2D TargetPosition = pCurrentTarget.lock()->GetPosition();
		Vector2D MyPosition = GetParent()->GetPosition();
		if ((TargetPosition - MyPosition).GetSizeSq() < 500.0f * 500.0f)
		{
			Stop();
		}
	}
}
