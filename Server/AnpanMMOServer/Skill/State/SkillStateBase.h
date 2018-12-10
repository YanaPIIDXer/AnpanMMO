#ifndef __SKILLSTATEBASE_H__
#define __SKILLSTATEBASE_H__

class SkillControl;

/**
 * �X�L���X�e�[�g���N���X
 */
class SkillStateBase
{

public:

	// �R���X�g���N�^
	SkillStateBase(SkillControl *pInControl);

	// �f�X�g���N�^
	virtual ~SkillStateBase() = 0;

	// ���t���[���̏���.
	virtual void Poll(s32 DeltaTime) {}

protected:

	// �X�L���R���g���[�����擾.
	SkillControl *GetControl() const { return pControl; }

private:

	// �X�L���R���g���[��
	SkillControl *pControl;

};

#endif		// #ifndef __SKILLSTATEBASE_H__
