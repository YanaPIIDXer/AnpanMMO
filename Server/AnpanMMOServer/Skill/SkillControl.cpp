#include "stdafx.h"
#include "SkillControl.h"
#include "Master/MasterData.h"
#include "State/SkillStateNutral.h"
#include "State/SkillStateCast.h"
#include "State/SkillStateAutoMove.h"

// コンストラクタ
SkillControl::SkillControl(CharacterBase *pInOwner)
	: pState(new SkillStateNutral(this))
	, pPrevState(NULL)
	, pOwner(pInOwner)
	, pTarget(NULL)
	, SkillId(0)
{
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
void SkillControl::Use(u32 InSkillId, CharacterBase *pInTarget)
{
	SkillId = InSkillId;
	pTarget = pInTarget;
	ChangeState(new SkillStateCast(this));
}

// ステート変更.
void SkillControl::ChangeState(SkillStateBase *pNewState)
{
	pPrevState = pState;
	pState = pNewState;
}

// キャストが完了した。
void SkillControl::CastFinished()
{
	if (OnCastFinishedFunc)
	{
		OnCastFinishedFunc();
	}

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
	if (OnActivateFunc)
	{
		OnActivateFunc();
	}

	// ここでStateをNutralに戻す。
	ChangeState(new SkillStateNutral(this));
}

// 何かやっているか？
bool SkillControl::IsActive() const
{
	return (pState->GetStateType() != Nutral);
}
