#include "stdafx.h"
#include "AnpanAIStateActive.h"
#include "Character/Anpan/AI/AnpanAI.h"
#include "AnpanAIStateNonActive.h"

// �R���X�g���N�^
AnpanAIStateActive::AnpanAIStateActive(Anpan *pInParent)
	: AnpanAIStateBase(pInParent)
{
	pCurrentTarget.reset();
}


// �X�V.
void AnpanAIStateActive::Update()
{
	weak_ptr<CharacterBase> pChara = GetAI()->GetHate().GetTop();
	if (pChara.expired())
	{
		// �w�C�g���X�g����L���������Ȃ��Ȃ����B
		GetAI()->ChangeState(new AnpanAIStateNonActive(GetParent()));
	}
}
