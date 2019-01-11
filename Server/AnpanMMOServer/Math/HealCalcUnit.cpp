/**
 * @file HealCalcUnit.cpp
 * @brief 回復計算クラス
 * @author YanaP
 */
#include "stdafx.h"
#include "HealCalcUnit.h"
#include "Math/Random.h"
#include "Master/SkillMaster.h"

const int HealCalcUnit::CorrectionMaxValue = 10;

// コンストラクタ
HealCalcUnit::HealCalcUnit(const CharacterParameter &InCharaParam, const SkillItem *pInSkillParam)
	: CharaParam(InCharaParam)
	, pSkillParam(pInSkillParam)
{
}

// 計算.
int HealCalcUnit::Calc() const
{
	int Value = pSkillParam->BonusInt + pSkillParam->BonusMnd;
	if (pSkillParam->CalcType != SkillItem::ITEM_HEAL)
	{
		Value += CharaParam.GetInt() + CharaParam.GetMnd();
	}

	Value += Random::Range<int>(0, CorrectionMaxValue);

	return Value;
}
