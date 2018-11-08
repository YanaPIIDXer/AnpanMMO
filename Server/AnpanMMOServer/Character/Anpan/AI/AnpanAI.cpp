#include "stdafx.h"
#include "AnpanAI.h"
#include "Character/Anpan/Anpan.h"
#include "State/AnpanAIStateBase.h"
#include "State/AnpanAIStateNonActive.h"

// �R���X�g���N�^
AnpanAI::AnpanAI(Anpan *pInParent)
	: pParent(pInParent)
	, pMovePacketData(NULL)
	, pRotatePacketData(NULL)
{
	ChangeState(new AnpanAIStateNonActive(pInParent));
}

// �f�X�g���N�^
AnpanAI::~AnpanAI()
{
	delete pState;
	pState = NULL;

	delete pMovePacketData;
	pMovePacketData = NULL;

	delete pRotatePacketData;
	pRotatePacketData = NULL;
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

// �ړ��p�P�b�g�f�[�^�̐���.
void AnpanAI::CreateMovePacketData(const Vector2D &Position, int Time)
{
	pMovePacketData = new AnpanMovePacketData(pParent->GetUuid(), Position, Time);
}

// �ړ��p�P�b�g�f�[�^�̎擾.
AnpanMovePacketData *AnpanAI::SweepMovePacketData()
{
	AnpanMovePacketData *pData = pMovePacketData;
	pMovePacketData = NULL;
	return pData;
}

// ��]�p�P�b�g�f�[�^�̐���.
void AnpanAI::CreateRotatePacketData(const Rotation &Rot, int Time)
{
	pRotatePacketData = new AnpanRotatePacketData(pParent->GetUuid(), Rot, Time);
}

// ��]�p�P�b�g�f�[�^�̎擾.
AnpanRotatePacketData *AnpanAI::SweepRotatePacketData()
{
	AnpanRotatePacketData *pData = pRotatePacketData;
	pRotatePacketData = NULL;
	return pData;
}
