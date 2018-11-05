#ifndef __DAMAGECALCUNIT_H__
#define __DAMAGECALCUNIT_H__

#include "Character/CharacterParameter.h"

/**
 * ダメージ計算クラス.
 */
class DamageCalcUnit
{

public:

	// コンストラクタ
	DamageCalcUnit(const CharacterParameter &InAttackerParam, const CharacterParameter &InDefencerParam);

	// デストラクタ
	~DamageCalcUnit() {}

	// 計算.
	int Calc() const;

private:

	// 各種補正最大値.
	static const int CorrectionMaxValue;

	// クリティカル発生率.
	static const int CriticalRate;

	// 攻撃側パラメータ
	CharacterParameter AttackerParam;

	// 防御側パラメータ
	CharacterParameter DefencerParam;

};

#endif		// #ifndef __DAMAGECALCUNIT_H__
