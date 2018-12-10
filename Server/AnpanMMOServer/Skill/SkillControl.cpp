#include "stdafx.h"
#include "SkillControl.h"
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
	ChangeState(new SkillStateAutoMove(this));
	if (OnCastFinishedFunc)
	{
		OnCastFinishedFunc();
	}
}

// キャンセル
void SkillControl::Cancel(u8 Reason)
{
	ChangeState(new SkillStateNutral(this));
	if (OnCancelFunc)
	{
		OnCancelFunc(Reason);
	}
}

// 発動.
void SkillControl::Activate()
{
	// ここでStateをNutralに戻す。
	ChangeState(new SkillStateNutral(this));
	if (OnActivateFunc)
	{
		OnActivateFunc();
	}
}
