#ifndef __SKILLSTATECAST_H__
#define __SKILLSTATECAST_H__

#include "SkillStateBase.h"

/**
 * �X�L���X�e�[�g�F�L���X�g��.
 */
class SkillStateCast : public SkillStateBase
{

public:

	// �R���X�g���N�^
	SkillStateCast(SkillControl *pInControl);

	// �f�X�g���N�^
	virtual ~SkillStateCast() {}

	// ���t���[���̏���.
	virtual void Poll(s32 DeltaTime);

private:

	// �L���X�g����.
	s32 CastTime;

};

#endif		// #ifndef __SKILLSTATECAST_H__
