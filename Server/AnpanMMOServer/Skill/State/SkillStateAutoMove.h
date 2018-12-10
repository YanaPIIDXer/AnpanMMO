#ifndef __SKILLSTATEAUTOMOVE_H__
#define __SKILLSTATEAUTOMOVE_H__

#include "SkillStateBase.h"

class CharacterBase;

/**
 * �X�L���X�e�[�g�F�I�[�g�ړ�.
 */
class SkillStateAutoMove : public SkillStateBase
{

public:

	// �R���X�g���N�^
	SkillStateAutoMove(SkillControl *pInContril);

	// �f�X�g���N�^
	virtual ~SkillStateAutoMove() {}

	// ���t���[���̏���.
	virtual void Poll(s32 DeltaTime);

private:

	// ��������.
	static const s32 AutoMoveLimitTime;

	// �o�ߎ���.
	s32 ElapsedTime;

	// ��������.
	s32 SkillDistance;

	// ���L��.
	CharacterBase *pOwner;

	// �^�[�Q�b�g.
	CharacterBase *pTarget;

};

#endif		// #ifndef __SKILLSTATEAUTOMOVE_H__
