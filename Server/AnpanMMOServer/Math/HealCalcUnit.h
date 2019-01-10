/**
 * @file HhealCalcUnit.h
 * @brief �񕜌v�Z�N���X
 * @author YanaP
 */
#ifndef __HEALCALCUNIT_H__
#define __HEALCALCUNIT_H__

#include "Character/CharacterParameter.h"

struct SkillItem;

/**
 * @class HealCalcUnit
 * @brief �񕜌v�Z�N���X.
 */
class HealCalcUnit
{

public:

	/**
	 * @brief �R���X�g���N�^
	 * @param[in] InAttackerParam �L�����p�����[�^
	 * @param[in] pInSkillParam �X�L���p�����[�^
	 */
	HealCalcUnit(const CharacterParameter &InCharaParam, const SkillItem *pInSkillParam);

	/**
	 * @fn int Calc()
	 * @brief �v�Z
	 * @return �񕜌v�Z����
	 */
	int Calc() const;

private:

	// �␳�ő�l.
	static const int CorrectionMaxValue;

	// �L�����p�����[�^
	CharacterParameter CharaParam;

	// �X�L���p�����[�^
	const SkillItem *pSkillParam;

};

#endif		// #ifndef __HEALCALCUNIT_H__
