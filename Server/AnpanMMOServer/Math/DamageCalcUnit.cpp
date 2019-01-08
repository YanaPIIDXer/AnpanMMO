/**
 * @file DamageCalcUnit.cpp
 * @brief ダメージ計算クラス
 * @author YanaP
 */
#include "stdafx.h"
#include "DamageCalcUnit.h"
#include "Math/Random.h"
#include "Master/SkillMaster.h"

const int DamageCalcUnit::CorrectionMaxValue = 10;
const int DamageCalcUnit::CriticalRate = 10;

// コンストラクタ
DamageCalcUnit::DamageCalcUnit(const CharacterParameter &InAttackerParam, const CharacterParameter &InDefencerParam, const SkillItem *pInSkillParam)
	: AttackerParam(InAttackerParam)
	, DefencerParam(InDefencerParam)
	, pSkillParam(pInSkillParam)
{
}

// 計算.
int DamageCalcUnit::Calc() const
{
	int Atk = static_cast<int>(((pSkillParam->CalcType == SkillItem::PHYSICAL) ? AttackerParam.Str + pSkillParam->BonusStr : AttackerParam.Int + pSkillParam->BonusInt) * 1.5f);
	int Def = ((pSkillParam->CalcType == SkillItem::PHYSICAL) ? DefencerParam.Def : DefencerParam.Mnd) + DefencerParam.Vit;
	
	if (Random::Range<int>(0, 100) <= CriticalRate)
	{
		// クリティカル。防御無視。
		Def = 0;
	}

	int Result = Atk - Def + Random::Range<int>(0, CorrectionMaxValue);
	if (Result <= 0)
	{
		Result = 1;
	}

	return Result;
}
