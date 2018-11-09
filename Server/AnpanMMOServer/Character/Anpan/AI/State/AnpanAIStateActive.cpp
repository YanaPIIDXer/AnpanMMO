#include "stdafx.h"
#include "AnpanAIStateActive.h"
#include "Character/Anpan/AI/AnpanAI.h"
#include "AnpanAIStateNonActive.h"
#include "Character/CharacterBase.h"
#include "Character/Anpan/Anpan.h"
#include "Math/MathUtil.h"
#include <math.h>

// コンストラクタ
AnpanAIStateActive::AnpanAIStateActive(Anpan *pInParent)
	: AnpanAIStateBase(pInParent)
	, ActionTimer(0)
	, CurrentState(Rotating)
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
	if (ActionTimer < 0)
	{
		ActionTimer = 0;
	}
	switch (CurrentState)
	{
		case Rotating:

			UpdateRotate();
			break;

		case Moving:

			UpdateMove();
			break;
	}
}


// 回転を更新.
void AnpanAIStateActive::UpdateRotate()
{

}

// 移動を更新.
void AnpanAIStateActive::UpdateMove()
{

}
