/**
 * @file DamageCalcUnit.h
 * @brief �_���[�W�v�Z�N���X
 * @author YanaP
 */
#ifndef __DAMAGECALCUNIT_H__
#define __DAMAGECALCUNIT_H__

#include "Character/CharacterParameter.h"

struct SkillItem;

/**
 * @class DamageCalcUnit
 * @brief �_���[�W�v�Z�N���X.
 */
class DamageCalcUnit
{

public:

	/**
	 * @brief �R���X�g���N�^
	 * @param[in] InAttackerParam �U�����p�����[�^
	 * @param[in] InDefencerParam �h�䑤�p�����[�^
	 * @param[in] pInSkillParam �X�L���p�����[�^
	 */
	DamageCalcUnit(const CharacterParameter &InAttackerParam, const CharacterParameter &InDefencerParam, const SkillItem *pInSkillParam);

	/**
	 * @brief �f�X�g���N�^
	 */
	~DamageCalcUnit() {}

	/**
	 * @fn int Calc()
	 * @brief �v�Z
	 * @return �_���[�W�v�Z����
	 */
	int Calc() const;

private:

	// �␳�ő�l.
	static const int CorrectionMaxValue;

	// �N���e�B�J��������.
	static const int CriticalRate;

	// �U�����p�����[�^
	CharacterParameter AttackerParam;

	// �h�䑤�p�����[�^
	CharacterParameter DefencerParam;

	// �X�L���p�����[�^
	const SkillItem *pSkillParam;

};

#endif		// #ifndef __DAMAGECALCUNIT_H__
