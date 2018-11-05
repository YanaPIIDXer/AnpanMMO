#include "stdafx.h"
#include "DamageCalcUnit.h"
#include <boost/random.hpp>
#include <boost/random/random_device.hpp>

const int DamageCalcUnit::CorrectionMaxValue = 10;
const int DamageCalcUnit::CriticalRate = 10;

// �R���X�g���N�^
DamageCalcUnit::DamageCalcUnit(const CharacterParameter &InAttackerParam, const CharacterParameter &InDefencerParam)
	: AttackerParam(InAttackerParam)
	, DefencerParam(InDefencerParam)
{
}

// �v�Z.
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
		// �N���e�B�J���B�h�䖳���B
		Def = 0;
	}

	int Result = Atk - Def;
	if (Result <= 0)
	{
		Result = 1;
	}

	return Result;
}
