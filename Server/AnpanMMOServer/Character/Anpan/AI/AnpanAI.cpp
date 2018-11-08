#include "stdafx.h"
#include "AnpanAI.h"
#include "State/AnpanAIStateBase.h"
#include "State/AnpanAIStateNonActive.h"

// コンストラクタ
AnpanAI::AnpanAI(Anpan *pInParent)
	: pParent(pInParent)
{
	ChangeState(new AnpanAIStateNonActive(pInParent));
}

// デストラクタ
AnpanAI::~AnpanAI()
{
	delete pState;
	pState = NULL;
}

// 毎フレームの処理.
void AnpanAI::Poll(int DeltaTime)
{
	pState->Poll(DeltaTime);
}

// ステート切り替え.
void AnpanAI::ChangeState(AnpanAIStateBase *pNewState)
{
	delete pState;
	pState = pNewState;
	pState->SetAI(this);
}
