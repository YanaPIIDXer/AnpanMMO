/**
 * @file DamageCalcUnit.cpp
 * @brief �_���[�W�v�Z�N���X
 * @author YanaP
 */
#include "stdafx.h"
#include "DamageCalcUnit.h"
#include "Math/Random.h"
#include "Master/SkillMaster.h"

const int DamageCalcUnit::CorrectionMaxValue = 10;
const int DamageCalcUnit::CriticalRate = 10;

// �R���X�g���N�^
DamageCalcUnit::DamageCalcUnit(const CharacterParameter &InAttackerParam, const CharacterParameter &InDefencerParam, const SkillItem *pInSkillParam)
	: AttackerParam(InAttackerParam)
	, DefencerParam(InDefencerParam)
	, pSkillParam(pInSkillParam)
{
}

// �v�Z.
int DamageCalcUnit::Calc() const
{
	int Atk = static_cast<int>(((pSkillParam->CalcType == SkillItem::PHYSICAL) ? AttackerParam.Str + pSkillParam->BonusStr : AttackerParam.Int + pSkillParam->BonusInt) * 1.5f);
	int Def = ((pSkillParam->CalcType == SkillItem::PHYSICAL) ? DefencerParam.Def : DefencerParam.Mnd) + DefencerParam.Vit;
	
	if (Random::Range<int>(0, 100) <= CriticalRate)
	{
		// �N���e�B�J���B�h�䖳���B
		Def = 0;
	}

	int Result = Atk - Def + Random::Range<int>(0, CorrectionMaxValue);
	if (Result <= 0)
	{
		Result = 1;
	}

	return Result;
}
