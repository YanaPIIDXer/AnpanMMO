// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#include "SkillControl.h"
#include "Master/MasterData.h"
#include "State/SkillStateNutral.h"
#include "State/SkillStateCast.h"
#include "State/SkillStateAutoMove.h"

// コンストラクタ
SkillControl::SkillControl()
	: pState(new SkillStateNutral(this))
	, pPrevState(nullptr)
	, pOwner(nullptr)
	, pTarget(nullptr)
{
}

// デストラクタ
SkillControl::~SkillControl()
{
	delete pPrevState;
	delete pState;
}

// 毎フレームの処理.
void SkillControl::Poll()
{
	if (pPrevState != nullptr)
	{
		delete pPrevState;
		pPrevState = nullptr;
	}

	pState->Poll();
}

// スキル使用.
void SkillControl::UseSkill(uint32 SkillId, ACharacterBase *pInTarget)
{
	SkillData = *MasterData::GetInstance().GetSkillMaster().Get(SkillId);
	pTarget = pInTarget;

	// キャスト開始.
	ChangeState(new SkillStateCast(this));
}

// キャストが完了した。
void SkillControl::OnCastFinished()
{
	ChangeState(new SkillStateAutoMove(this));
}

// スキルが発動した。
void SkillControl::OnActivate()
{
	// ニュートラルに戻す。
	ChangeState(new SkillStateNutral(this));
}

// キャンセルされた
void SkillControl::OnCancel()
{
	// ニュートラルに戻す。
	ChangeState(new SkillStateNutral(this));
}

// 何かしているか？
bool SkillControl::IsActive() const
{
	return (pState->GetStateType() != ESkillStateType::Nutral);
}


// State切り替え
void SkillControl::ChangeState(SkillStateBase *pNewState)
{
	pPrevState = pState;
	pState = pNewState;
	pState->BeginState();
}
