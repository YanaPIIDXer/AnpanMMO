#include "stdafx.h"
#include "AnpanAI.h"
#include "State/AnpanAIStateBase.h"
#include "State/AnpanAIStateNonActive.h"

// �R���X�g���N�^
AnpanAI::AnpanAI(Anpan *pInParent)
	: pParent(pInParent)
{
	ChangeState(new AnpanAIStateNonActive(pInParent));
}

// �f�X�g���N�^
AnpanAI::~AnpanAI()
{
	delete pState;
	pState = NULL;
}

// ���t���[���̏���.
void AnpanAI::Poll(int DeltaTime)
{
	pState->Poll(DeltaTime);
}

// �X�e�[�g�؂�ւ�.
void AnpanAI::ChangeState(AnpanAIStateBase *pNewState)
{
	delete pState;
	pState = pNewState;
	pState->SetAI(this);
}
