/**
 * @file DamageCalcUnit.h
 * @brief ダメージ計算クラス
 * @author YanaP
 */
#ifndef __DAMAGECALCUNIT_H__
#define __DAMAGECALCUNIT_H__

#include "Character/CharacterParameter.h"

struct SkillItem;

/**
 * @class DamageCalcUnit
 * @brief ダメージ計算クラス.
 */
class DamageCalcUnit
{

public:

	/**
	 * @brief コンストラクタ
	 * @param[in] InAttackerParam 攻撃側パラメータ
	 * @param[in] InDefencerParam 防御側パラメータ
	 * @param[in] pInSkillParam スキルパラメータ
	 */
	DamageCalcUnit(const CharacterParameter &InAttackerParam, const CharacterParameter &InDefencerParam, const SkillItem *pInSkillParam);

	/**
	 * @brief デストラクタ
	 */
	~DamageCalcUnit() {}

	/**
	 * @fn int Calc()
	 * @brief 計算
	 * @return ダメージ計算結果
	 */
	int Calc() const;

private:

	// 補正最大値.
	static const int CorrectionMaxValue;

	// クリティカル発生率.
	static const int CriticalRate;

	// 攻撃側パラメータ
	CharacterParameter AttackerParam;

	// 防御側パラメータ
	CharacterParameter DefencerParam;

	// スキルパラメータ
	const SkillItem *pSkillParam;

};

#endif		// #ifndef __DAMAGECALCUNIT_H__
