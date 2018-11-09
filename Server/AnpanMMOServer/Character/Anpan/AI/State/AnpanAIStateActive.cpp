#include "stdafx.h"
#include "AnpanAIStateActive.h"
#include "Character/Anpan/AI/AnpanAI.h"
#include "AnpanAIStateNonActive.h"
#include "Character/CharacterBase.h"
#include "Character/Anpan/Anpan.h"
#include "Math/MathUtil.h"
#include <math.h>

// �R���X�g���N�^
AnpanAIStateActive::AnpanAIStateActive(Anpan *pInParent)
	: AnpanAIStateBase(pInParent)
	, ActionTimer(0)
	, CurrentState(Rotating)
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


// ��]���X�V.
void AnpanAIStateActive::UpdateRotate()
{

}

// �ړ����X�V.
void AnpanAIStateActive::UpdateMove()
{

}
