#include "stdafx.h"
#include "AnpanAI.h"
#include "Character/Anpan/Anpan.h"
#include "State/AnpanAIStateBase.h"
#include "State/AnpanAIStateNonActive.h"

// �R���X�g���N�^
AnpanAI::AnpanAI(Anpan *pInParent)
	: pParent(pInParent)
	, bIsNeedSendStopPacket(false)
	, pPrevState(NULL)
{
	pMovePacketData.reset();
	pRotatePacketData.reset();
	ChangeState(new AnpanAIStateNonActive(pInParent));
}

// �f�X�g���N�^
AnpanAI::~AnpanAI()
{
	delete pState;
	pState = NULL;

	delete pPrevState;
	pPrevState = NULL;

	pMovePacketData.reset();
	pRotatePacketData.reset();
}

// ���t���[���̏���.
void AnpanAI::Poll(int DeltaTime)
{
	if (pPrevState != NULL)
	{
		delete pPrevState;
		pPrevState = NULL;
	}
	pState->Poll(DeltaTime);
	HateManager.Poll();
}

// �X�e�[�g�؂�ւ�.
void AnpanAI::ChangeState(AnpanAIStateBase *pNewState)
{
	pPrevState = pState;
	pState = pNewState;
	pState->SetAI(this);
}

// �ړ��p�P�b�g�f�[�^�̐���.
void AnpanAI::CreateMovePacketData(const Vector2D &Position, int Time)
{
	pMovePacketData = shared_ptr<AnpanMovePacketData>(new AnpanMovePacketData(pParent->GetUuid(), Position, Time));
}

// �ړ��p�P�b�g�f�[�^�̎擾.
shared_ptr<AnpanMovePacketData> AnpanAI::SweepMovePacketData()
{
	shared_ptr<AnpanMovePacketData> pData = pMovePacketData;
	pMovePacketData.reset();
	return pData;
}

// ��]�p�P�b�g�f�[�^�̐���.
void AnpanAI::CreateRotatePacketData(const Rotation &Rot, int Time)
{
	pRotatePacketData = shared_ptr<AnpanRotatePacketData>(new AnpanRotatePacketData(pParent->GetUuid(), Rot, Time));
}

// ��]�p�P�b�g�f�[�^�̎擾.
shared_ptr<AnpanRotatePacketData> AnpanAI::SweepRotatePacketData()
{
	shared_ptr<AnpanRotatePacketData> pData = pRotatePacketData;
	pRotatePacketData.reset();
	return pData;
}

// ��~�p�P�b�g�̑��M���擾.
bool AnpanAI::SweepSendStopPacketFlag()
{
	bool bSend = bIsNeedSendStopPacket;
	bIsNeedSendStopPacket = false;
	return bSend;
}

// �_���[�W���󂯂��B
void AnpanAI::OnDamaged(weak_ptr<CharacterBase> pAttacker, int DamageValue)
{
	HateManager.Add(pAttacker, DamageValue);
	pState->OnDamaged();
}
