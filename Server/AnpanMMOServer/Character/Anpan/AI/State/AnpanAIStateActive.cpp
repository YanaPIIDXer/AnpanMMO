#include "stdafx.h"
#include "AnpanAIStateActive.h"
#include "Character/Anpan/AI/AnpanAI.h"
#include "AnpanAIStateNonActive.h"

// コンストラクタ
AnpanAIStateActive::AnpanAIStateActive(Anpan *pInParent)
	: AnpanAIStateBase(pInParent)
{
	pCurrentTarget.reset();
}


// 更新.
void AnpanAIStateActive::Update()
{
	weak_ptr<CharacterBase> pChara = GetAI()->GetHate().GetTop();
	if (pChara.expired())
	{
		// ヘイトリストからキャラがいなくなった。
		GetAI()->ChangeState(new AnpanAIStateNonActive(GetParent()));
	}
}
