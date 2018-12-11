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

// コンストラクタ
SkillControl::SkillControl(CharacterBase *pInOwner)
	: pState(new SkillStateNutral(this))
	, pPrevState(NULL)
	, pOwner(pInOwner)
	, SkillId(0)
{
	pTarget.reset();
}

// デストラクタ
SkillControl::~SkillControl()
{
	delete pPrevState;
	delete pState;
}

// 毎フレームの処理.
void SkillControl::Poll(s32 DeltaTime)
{
	if (pPrevState != NULL)
	{
		delete pPrevState;
		pPrevState = NULL;
	}

	pState->Poll(DeltaTime);
}

// 使用.
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

// キャストが完了した。
void SkillControl::CastFinished()
{
	PacketSkillCastFinish Packet(pOwner->GetCharacterType(), pOwner->GetUuid());
	AreaPtr pArea = pOwner->GetArea();
	pArea.lock()->BroadcastPacket(&Packet);

	const SkillItem *pItem = MasterData::GetInstance().GetSkillMaster().GetItem(SkillId);
	if (pItem->RangeType == SkillItem::NORMAL)
	{
		// 通常スキルならオート移動へ。
		ChangeState(new SkillStateAutoMove(this));
	}
	else
	{
		// そうでないなら即時発動。
		Activate();
	}
}

// キャンセル
void SkillControl::Cancel(u8 Reason)
{
	if (OnCancelFunc)
	{
		OnCancelFunc(Reason);
	}

	ChangeState(new SkillStateNutral(this));
}

// 発動.
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
					// @HACK:とりあえずダメージ計算ユニットを使用。
					DamageCalcUnit Calc(pOwner->GetParameter(), Targets[i]->GetParameter());
					s32 Value = Calc.Calc();
					Targets[i]->Heal(Value);
				}
				break;

			case SkillItem::BUFF:

				// @TODO:バフ実装時に実装する。
				break;

			case SkillItem::DEBUFF:

				// @TODO:デバフ実装時に実装する。
				break;
		}
	}

	pOwner->StartRecast(SkillId);

	// ここでStateをNutralに戻す。
	ChangeState(new SkillStateNutral(this));
}

// 何かやっているか？
bool SkillControl::IsActive() const
{
	return (pState->GetStateType() != Nutral);
}


// ステート変更.
void SkillControl::ChangeState(SkillStateBase *pNewState)
{
	pPrevState = pState;
	pState = pNewState;
	pState->BeginState();
}
