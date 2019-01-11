/**
 * @file HhealCalcUnit.h
 * @brief 回復計算クラス
 * @author YanaP
 */
#ifndef __HEALCALCUNIT_H__
#define __HEALCALCUNIT_H__

#include "Character/CharacterParameter.h"

struct SkillItem;

/**
 * @class HealCalcUnit
 * @brief 回復計算クラス.
 */
class HealCalcUnit
{

public:

	/**
	 * @brief コンストラクタ
	 * @param[in] InAttackerParam キャラパラメータ
	 * @param[in] pInSkillParam スキルパラメータ
	 */
	HealCalcUnit(const CharacterParameter &InCharaParam, const SkillItem *pInSkillParam);

	/**
	 * @fn int Calc()
	 * @brief 計算
	 * @return 回復計算結果
	 */
	int Calc() const;

private:

	// 補正最大値.
	static const int CorrectionMaxValue;

	// キャラパラメータ
	CharacterParameter CharaParam;

	// スキルパラメータ
	const SkillItem *pSkillParam;

};

#endif		// #ifndef __HEALCALCUNIT_H__
