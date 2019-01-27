/**
 * @file AnpanAIStateActive.cpp
 * @brief �A���p���`�h�X�e�[�g�F�A�N�e�B�u���
 * @author YanaP
 */
#include "stdafx.h"
#include "AnpanAIStateActive.h"
#include "Character/Anpan/AI/AnpanAI.h"
#include "AnpanAIStateNonActive.h"
#include "Character/CharacterBase.h"
#include "Character/Anpan/Anpan.h"
#include "Character/Anpan/AI/AIGenerator.h"
#include "Master/MasterData.h"
#include "Math/MathUtil.h"
#include <math.h>

// �R���X�g���N�^
AnpanAIStateActive::AnpanAIStateActive(Anpan *pInParent)
	: AnpanAIStateBase(pInParent)
	, WaitTimer(0)
	, bInitializedAction(false)
	, SkillDistance(0.0f)
{
	pCurrentTarget.reset();
	pSkillTarget.reset();
	pCurrentAction = AIGenerator::GetInstance().Get(pInParent->GetAIId());
}


// �X�V.
void AnpanAIStateActive::Update(int DeltaTime)
{
	CharacterPtr pChara = GetAI()->GetHate().GetTop();
	if (pChara.expired() && !GetParent()->IsSkillActive())
	{
		// �w�C�g���X�g����L���������Ȃ��Ȃ����B
		GetAI()->Stop();
		GetAI()->ChangeState(new AnpanAIStateNonActive(GetParent()));
		return;
	}

	if (pCurrentTarget.expired() || pChara.lock().get() != pCurrentTarget.lock().get())
	{
		pCurrentTarget = pChara;
	}

	if (!bInitializedAction)
	{
		InitializeAction();
		bInitializedAction = true;
	}

	switch (pCurrentAction.lock()->Action)
	{
		case AnpanAIItem::WAIT:

			WaitTimer -= DeltaTime;
			if (WaitTimer <= 0)
			{
				ChangeToNextAction();
			}
			break;
		
		case AnpanAIItem::APPROACH:

			if (IsApproached())
			{
				Stop();
				ChangeToNextAction();
			}
			break;

		case AnpanAIItem::KEEP_DISTANCE:

			if (IsKeepedDistanceToTarget())
			{
				Stop();
				ChangeToNextAction();
			}
			break;

		case AnpanAIItem::USE_SKILL:

			if (GetParent()->IsSkillCasting())
			{
				// �L���X�g���͂`�h�͉������Ȃ��B
			}
			if (GetParent()->IsSkillAutoMoving())
			{
				// �I�[�g�ړ��J�n.
				if (!IsRotating())
				{
					RotateToTarget();
				}
				if (!IsMoving())
				{
					MoveToTarget();
				}
			}
			else if (GetParent()->IsSkillActive())
			{
				// �X�L���t���[���I�������B
				ChangeToNextAction();
			}
			break;
	}
}


// �^�[�Q�b�g�̕����������B
void AnpanAIStateActive::RotateToTarget()
{
	CharacterPtr pTarget = pCurrentTarget;
	if (GetParent()->IsSkillActive())
	{
		pTarget = pSkillTarget;
	}

	Vector3D TargetPos = pTarget.lock()->GetPosition();
	Vector3D MyPos = GetParent()->GetPosition();
	TargetPos.Z = MyPos.Z;		// �����͍l�����Ȃ��B
	Vector3D TargetVec = (TargetPos - MyPos).GetNormalized();
	Vector3D CenterVec = GetParent()->GetCenterVec();

	float Dot = MathUtil::Dot(TargetVec, CenterVec);
	float Rad = acos(Dot);
	float Deg = MathUtil::RadToDeg(Rad);

	if (isnan(Deg))
	{
		Deg = 0.0f;
	}

	if (MathUtil::Cross(CenterVec, TargetVec).X < 0.0f)
	{
		Deg *= -1.0f;
	}
	
	SetRotate(Rotation(Deg), 300);
}

// �^�[�Q�b�g�Ɍ������Ĉړ�����B
void AnpanAIStateActive::MoveToTarget()
{
	if (IsApproached())
	{
		if (!GetParent()->IsSkillActive())
		{
			ChangeToNextAction();
		}
		return;
	}
	
	CharacterPtr pTarget = pCurrentTarget;
	if (GetParent()->IsSkillActive())
	{
		pTarget = pSkillTarget;
	}

	Vector3D TargetPos = pTarget.lock()->GetPosition();
	Vector3D MyPos = GetParent()->GetPosition();
	TargetPos.Z = MyPos.Z;		// �����͍l�����Ȃ��B
	Vector3D TargetVec = TargetPos - MyPos;
	float Size = TargetVec.GetSize();
	TargetVec.Normalize();
	if (!GetParent()->IsSkillActive())
	{
		TargetVec *= (Size - static_cast<float>(pCurrentAction.lock()->Value));
	}
	else
	{
		TargetVec *= (Size - SkillDistance);
	}
	
	SetMove(TargetVec, 1000);
}

// �ڋ߂��Ă��邩�H
bool AnpanAIStateActive::IsApproached()
{
	float ApproachDist = static_cast<float>(pCurrentAction.lock()->Value);
	if (GetParent()->IsSkillActive())
	{
		ApproachDist = SkillDistance;
	}

	Vector3D TargetVec = pCurrentTarget.lock()->GetPosition() - GetParent()->GetPosition();
	return (TargetVec.GetSizeSq() < ApproachDist * ApproachDist);
}

// �^�[�Q�b�g���狗�������B
void AnpanAIStateActive::KeepDistanceToTarget()
{
	if (IsKeepedDistanceToTarget())
	{
		ChangeToNextAction();
		return;
	}

	Vector3D TargetPos = pCurrentTarget.lock()->GetPosition();
	Vector3D MyPos = GetParent()->GetPosition();
	TargetPos.Z = MyPos.Z;		// �����͍l�����Ȃ��B
	Vector3D TargetVec = MyPos - TargetPos;
	TargetVec.Normalize();
	TargetVec *= static_cast<float>(pCurrentAction.lock()->Value);

	SetMove(TargetVec, 1000);
}

// �^�[�Q�b�g���狗������������H
bool AnpanAIStateActive::IsKeepedDistanceToTarget()
{
	Vector3D TargetVec = pCurrentTarget.lock()->GetPosition() - GetParent()->GetPosition();
	float KeepDist = static_cast<float>(pCurrentAction.lock()->Value);
	return (TargetVec.GetSizeSq() < KeepDist * KeepDist);
}

// �X�L���g�p.
void AnpanAIStateActive::UseSkill()
{
	u32 SkillId = pCurrentAction.lock()->Value;
	pSkillTarget = pCurrentTarget;
	const SkillItem *pItem = MasterData::GetInstance().GetSkillMaster().GetItem(SkillId);
	if (pItem == NULL)
	{
		std::cout << "AnpanAI Warning! SkillID:" << SkillId << " is Invalid." << std::endl;
		ChangeToNextAction();
		return;
	}

	switch (pItem->SkillType)
	{
		case SkillItem::HEAL:
		case SkillItem::BUFF:

			pSkillTarget = GetParent()->shared_from_this();
			break;
	}

	GetParent()->UseSkill(SkillId, pSkillTarget);
	SkillDistance = static_cast<float>(pItem->Distance);
}

// ���̃A�N�V�����ɕύX.
void AnpanAIStateActive::ChangeToNextAction()
{
	pCurrentAction = pCurrentAction.lock()->pNextAction;
	InitializeAction();
}

// �A�N�V�����̏�����.
void AnpanAIStateActive::InitializeAction()
{
	switch (pCurrentAction.lock()->Action)
	{
		case AnpanAIItem::WAIT:

			WaitTimer = pCurrentAction.lock()->Value;
			break;

		case AnpanAIItem::APPROACH:

			RotateToTarget();
			MoveToTarget();
			break;

		case AnpanAIItem::KEEP_DISTANCE:

			KeepDistanceToTarget();
			break;

		case AnpanAIItem::USE_SKILL:

			UseSkill();
			break;

		case AnpanAIItem::CHANGE_STAGE:

			ChangeToNextAction();
			break;
	}
}
