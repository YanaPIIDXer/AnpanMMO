#include "stdafx.h"
#include "DamageCalcUnit.h"
#include "Math/Random.h"

const int DamageCalcUnit::CorrectionMaxValue = 10;
const int DamageCalcUnit::CriticalRate = 10;

// コンストラクタ
DamageCalcUnit::DamageCalcUnit(const CharacterParameter &InAttackerParam, const CharacterParameter &InDefencerParam)
	: AttackerParam(InAttackerParam)
	, DefencerParam(InDefencerParam)
{
}

// 計算.
int DamageCalcUnit::Calc() const
{
	int Atk = AttackerParam.Atk + Random::Range<int>(0, CorrectionMaxValue);
	int Def = DefencerParam.Def + Random::Range<int>(0, CorrectionMaxValue);
	
	if (Random::Range<int>(0, 100) <= CriticalRate)
	{
		// クリティカル。防御無視。
		Def = 0;
	}

	int Result = Atk - Def;
	if (Result <= 0)
	{
		Result = 1;
	}

	return Result;
}
