/**
 * @file AnpanAI.cpp
 * @brief �A���p���`�h�N���X
 * @author YanaP
 */
#include "stdafx.h"
#include "AnpanAI.h"
#include "Character/Anpan/Anpan.h"
#include "State/AnpanAIStateBase.h"
#include "State/AnpanAIStateNonActive.h"
#include "Master/SkillMaster.h"

// �R���X�g���N�^
AnpanAI::AnpanAI(Anpan *pInParent)
	: pParent(pInParent)
	, pState(NULL)
	, pPrevState(NULL)
	, bIsNeedSendStopPacket(false)
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

	if (!pParent->IsParalysis())
	{
		pState->Poll(DeltaTime);
	}
	HateManager.Poll(DeltaTime);
}

// �X�e�[�g�؂�ւ�.
void AnpanAI::ChangeState(AnpanAIStateBase *pNewState)
{
	pPrevState = pState;
	pState = pNewState;
	pState->SetAI(this);
}

// �ړ��p�P�b�g�f�[�^�̐���.
void AnpanAI::CreateMovePacketData(const Vector3D &Position, int Time)
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

// ��~.
void AnpanAI::Stop()
{
	pState->Stop();
}

// �X�L����H������B
void AnpanAI::OnSkillReceived(CharacterPtr pCharacter, const SkillItem *pSkill)
{
	if (pCharacter.lock().get() == pParent) { return; }
	HateManager.Add(pCharacter, pSkill->VolatileHate, pSkill->AccumulateHate);
}
