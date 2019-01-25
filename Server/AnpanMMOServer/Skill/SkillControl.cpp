#include "stdafx.h"
#include "SkillControl.h"
#include "Master/MasterData.h"
#include "Character/CharacterBase.h"
#include "Character/Player/PlayerCharacter.h"
#include "Character/Anpan/Anpan.h"
#include "Math/DamageCalcUnit.h"
#include "Math/HealCalcUnit.h"
#include "Math/Random.h"
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
	, ItemId(0)
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
	if (pOwner->IsRecasting(InSkillId))
	{
		Cancel(PacketSkillUseFailed::RecastTime);
		return;
	}

	if (MasterData::GetInstance().GetSkillMaster().GetItem(InSkillId) == NULL)
	{
		Cancel(PacketSkillUseFailed::InvalidSkill);
		return;
	}

	if (pOwner->IsParalysis())
	{
		Cancel(PacketSkillUseFailed::Paralysis);
		return;
	}

	SkillId = InSkillId;
	ItemId = 0;
	pTarget = pInTarget;
	ChangeState(new SkillStateCast(this));
}

// アイテム使用.
void SkillControl::UseItem(u32 InItemId, CharacterPtr pInTarget)
{
	const ItemItem *pItem = MasterData::GetInstance().GetItemMaster().GetItem(InItemId);
	if (pItem == NULL || pItem->SkillId == 0)
	{
		Cancel(PacketSkillUseFailed::Cancel);
		return;
	}
	Use(pItem->SkillId, pInTarget);
	ItemId = InItemId;
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
			case SkillItem::ITEM_HEAL:

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
					DamageCalcUnit Calc(pOwner->GetParameter(), Targets[i]->GetParameter(), pItem);
					s32 Value = Calc.Calc();
					Targets[i]->ApplyDamage(Value);
					if (Targets[i]->IsDead() && OnKilledFunc)
					{						
						OnKilledFunc(Targets[i]);
					}
				}
				break;

			case SkillItem::HEAL:
			case SkillItem::ITEM_HEAL:
				{
					HealCalcUnit Calc(pOwner->GetParameter(), pItem);
					s32 Value = Calc.Calc();
					Targets[i]->Heal(Value);
				}
				break;
		}

		// バフ（デバフ）が設定されていれば発生させる。
		if (pItem->BuffId != 0)
		{
			Targets[i]->AddBuff(pItem->BuffId);
		}
	}

	pOwner->StartRecast(SkillId);

	if (ItemId != 0 && OnUsedItemFunc)
	{
		OnUsedItemFunc(ItemId);
	}
	ItemId = 0;

	// ここでStateをNutralに戻す。
	ChangeState(new SkillStateNutral(this));
}

// 何かやっているか？
bool SkillControl::IsActive() const
{
	return (pState->GetStateType() != Nutral);
}

// キャスト中か？
bool SkillControl::IsCasting() const
{
	return (pState->GetStateType() == Cast);
}


// ステート変更.
void SkillControl::ChangeState(SkillStateBase *pNewState)
{
	pPrevState = pState;
	pState = pNewState;
	pState->BeginState();
}
