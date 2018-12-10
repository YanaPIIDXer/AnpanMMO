#ifndef __SKILLSTATEBASE_H__
#define __SKILLSTATEBASE_H__

class SkillControl;

// �X�L���X�e�[�g�̎��.
enum ESkillStateType
{
	// �������Ă��Ȃ�
	Nutral,

	// �L���X�g��.
	Cast,

	// �I�[�g�ړ�.
	AutoMove,
};

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

	// �X�e�[�g�^�C�v���擾.
	virtual ESkillStateType GetStateType() = 0;

protected:

	// �X�L���R���g���[�����擾.
	SkillControl *GetControl() const { return pControl; }

private:

	// �X�L���R���g���[��
	SkillControl *pControl;

};

#endif		// #ifndef __SKILLSTATEBASE_H__
