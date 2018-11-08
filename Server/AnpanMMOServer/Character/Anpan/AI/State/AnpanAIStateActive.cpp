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
	}

	if (pCurrentTarget.expired() || pChara.lock().get() != pCurrentTarget.lock().get())
	{
		pCurrentTarget = pChara;
	}

	MoveTimer -= DeltaTime;
	if (MoveTimer <= 0)
	{
		Vector2D TargetPosition = pCurrentTarget.lock()->GetPosition();
		Vector2D MyPosition = GetParent()->GetPosition();
		if ((TargetPosition - MyPosition).GetSizeSq() < 500.0f * 500.0f) { return; }
		Vector2D MoveVec = (TargetPosition - MyPosition).GetNormalized();
		float Dot = MoveVec.Dot(GetParent()->GetCenterVec());
		float Angle = MathUtil::RadToDeg(Dot);
		Angle += GetParent()->GetRotation().Get();
		MoveVec *= 1000.0f;
		MoveTimer = 1000;
		SetMove(MyPosition + MoveVec, MoveTimer);
		SetRotate(Rotation(Angle), MoveTimer);
		GetAI()->CreateMovePacketData(MyPosition + MoveVec, MoveTimer);
		GetAI()->CreateRotatePacketData(Rotation(Angle), MoveTimer);
	}
	else
	{
		Vector2D TargetPosition = pCurrentTarget.lock()->GetPosition();
		Vector2D MyPosition = GetParent()->GetPosition();
		if ((TargetPosition - MyPosition).GetSizeSq() < 500.0f * 500.0f)
		{
			Stop();
			GetAI()->SetSendStopPacket();
		}
	}
}
