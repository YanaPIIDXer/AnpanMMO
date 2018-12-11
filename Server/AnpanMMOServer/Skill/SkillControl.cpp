#include "stdafx.h"
#include "SkillControl.h"
#include "Master/MasterData.h"
#include "Character/CharacterBase.h"
#include "Math/DamageCalcUnit.h"
#include "State/SkillStateNutral.h"
#include "State/SkillStateCast.h"
#include "State/SkillStateAutoMove.h"
#include "Packet/CharacterType.h"
#include "Packet/PacketSkillCastFinish.h"
#include "Packet/PacketSkillActivate.h"
#include "Packet/PacketSkillUseFailed.h"

// �R���X�g���N�^
SkillControl::SkillControl(CharacterBase *pInOwner)
	: pState(new SkillStateNutral(this))
	, pPrevState(NULL)
	, pOwner(pInOwner)
	, SkillId(0)
{
	pTarget.reset();
}

// �f�X�g���N�^
SkillControl::~SkillControl()
{
	delete pPrevState;
	delete pState;
}

// ���t���[���̏���.
void SkillControl::Poll(s32 DeltaTime)
{
	if (pPrevState != NULL)
	{
		delete pPrevState;
		pPrevState = NULL;
	}

	pState->Poll(DeltaTime);
}

// �g�p.
void SkillControl::Use(u32 InSkillId, CharacterPtr pInTarget)
{
	if (pOwner->GetSkillRecastManager().IsRecast(InSkillId))
	{
		Cancel(PacketSkillUseFailed::RecastTime);
		return;
	}

	SkillId = InSkillId;
	pTarget = pInTarget;
	ChangeState(new SkillStateCast(this));
}

// �L���X�g�����������B
void SkillControl::CastFinished()
{
	PacketSkillCastFinish Packet(pOwner->GetCharacterType(), pOwner->GetUuid());
	AreaPtr pArea = pOwner->GetArea();
	pArea.lock()->BroadcastPacket(&Packet);

	const SkillItem *pItem = MasterData::GetInstance().GetSkillMaster().GetItem(SkillId);
	if (pItem->RangeType == SkillItem::NORMAL)
	{
		// �ʏ�X�L���Ȃ�I�[�g�ړ��ցB
		ChangeState(new SkillStateAutoMove(this));
	}
	else
	{
		// �����łȂ��Ȃ瑦�������B
		Activate();
	}
}

// �L�����Z��
void SkillControl::Cancel(u8 Reason)
{
	if (OnCancelFunc)
	{
		OnCancelFunc(Reason);
	}

	ChangeState(new SkillStateNutral(this));
}

// ����.
void SkillControl::Activate()
{
	PacketSkillActivate Packet(pOwner->GetCharacterType(), pOwner->GetUuid(), SkillId);
	AreaPtr pArea = pOwner->GetArea();
	pArea.lock()->BroadcastPacket(&Packet);

	std::vector<CharacterBase *> Targets;
	const SkillItem *pItem = MasterData::GetInstance().GetSkillMaster().GetItem(SkillId);
	if (pItem->RangeType == SkillItem::NORMAL)
	{
		if (!pTarget.expired())
		{
			Targets.push_back(pTarget.lock().get());
		}
	}
	else
	{
		u8 TargetType = 0;
		switch (pItem->SkillType)
		{
			case SkillItem::ATTACK:
			case SkillItem::DEBUFF:

				if (pOwner->GetCharacterType() == CharacterType::Player)
				{
					TargetType = CharacterType::Enemy;
				}
				else
				{
					TargetType = CharacterType::Player;
				}
				break;

			case SkillItem::HEAL:
			case SkillItem::BUFF:

				TargetType = pOwner->GetCharacterType();
				break;
		}

		Vector3D Center = pOwner->GetPosition();
		Center += (pOwner->GetCenterVec() * (float) pItem->Distance);
		switch (pItem->RangeType)
		{
			case SkillItem::RANGE_CIRCLE:

				pArea.lock()->CollectCircle(Center, (float) pItem->RangeX, TargetType, Targets);
				break;

			case SkillItem::RANGE_BOX:

				pArea.lock()->CollectBox(Center, (float) pItem->RangeX, (float) pItem->RangeY, TargetType, Targets);
				break;
		}
	}

	for (u32 i = 0; i < Targets.size(); i++)
	{
		switch (pItem->SkillType)
		{
			case SkillItem::ATTACK:

				{
					DamageCalcUnit Calc(pOwner->GetParameter(), Targets[i]->GetParameter());
					s32 Value = Calc.Calc();
					Targets[i]->ApplyDamage(pOwner->shared_from_this(), Value);
				}
				break;

			case SkillItem::HEAL:

				{
					// @HACK:�Ƃ肠�����_���[�W�v�Z���j�b�g���g�p�B
					DamageCalcUnit Calc(pOwner->GetParameter(), Targets[i]->GetParameter());
					s32 Value = Calc.Calc();
					Targets[i]->Heal(Value);
				}
				break;

			case SkillItem::BUFF:

				// @TODO:�o�t�������Ɏ�������B
				break;

			case SkillItem::DEBUFF:

				// @TODO:�f�o�t�������Ɏ�������B
				break;
		}
	}

	pOwner->StartRecast(SkillId);

	// ������State��Nutral�ɖ߂��B
	ChangeState(new SkillStateNutral(this));
}

// ��������Ă��邩�H
bool SkillControl::IsActive() const
{
	return (pState->GetStateType() != Nutral);
}


// �X�e�[�g�ύX.
void SkillControl::ChangeState(SkillStateBase *pNewState)
{
	pPrevState = pState;
	pState = pNewState;
	pState->BeginState();
}
