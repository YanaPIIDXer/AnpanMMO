#include "stdafx.h"
#include "AnpanAI.h"
#include "State/AnpanAIStateNonActive.h"

// コンストラクタ
AnpanAI::AnpanAI(Anpan *pInParent)
	: pParent(pInParent)
	, pState(new AnpanAIStateNonActive(pInParent))
{
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
