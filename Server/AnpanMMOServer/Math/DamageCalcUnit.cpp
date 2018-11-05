#include "stdafx.h"
#include "DamageCalcUnit.h"
#include <boost/random.hpp>
#include <boost/random/random_device.hpp>

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
	boost::random::random_device SeedGen;
	boost::random::mt19937 Gen(SeedGen);

	boost::random::uniform_int_distribution<> CorrectionDist(0, CorrectionMaxValue);
	int Atk = AttackerParam.Atk + CorrectionDist(Gen);
	int Def = DefencerParam.Def + CorrectionDist(Gen);
	
	boost::random::uniform_int_distribution<> CriticalRateDist(0, 100);
	if (CriticalRateDist(Gen) <= CriticalRate)
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
