#ifndef __SKILLSTATENUTRAL_H__
#define __SKILLSTATENUTRAL_H__

#include "SkillStateBase.h"

/**
 * �X�L���X�e�[�g�F�������Ă��Ȃ�
 */
class SkillStateNutral : public SkillStateBase
{

public:

	// �R���X�g���N�^
	SkillStateNutral(SkillControl *pInControl);

	// �f�X�g���N�^
	virtual ~SkillStateNutral() {}

	// �X�e�[�g�^�C�v���擾.
	virtual ESkillStateType GetStateType() { return Nutral; }

};


#endif		// #ifndef __SKILLSTATENUTRAL_H__