#ifndef __DAMAGECALCUNIT_H__
#define __DAMAGECALCUNIT_H__

#include "Character/CharacterParameter.h"

/**
 * �_���[�W�v�Z�N���X.
 */
class DamageCalcUnit
{

public:

	// �R���X�g���N�^
	DamageCalcUnit(const CharacterParameter &InAttackerParam, const CharacterParameter &InDefencerParam);

	// �f�X�g���N�^
	~DamageCalcUnit() {}

	// �v�Z.
	int Calc() const;

private:

	// �e��␳�ő�l.
	static const int CorrectionMaxValue;

	// �N���e�B�J��������.
	static const int CriticalRate;

	// �U�����p�����[�^
	CharacterParameter AttackerParam;

	// �h�䑤�p�����[�^
	CharacterParameter DefencerParam;

};

#endif		// #ifndef __DAMAGECALCUNIT_H__
