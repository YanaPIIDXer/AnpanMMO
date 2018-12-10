#ifndef __SKILLCONTROL_H__
#define __SKILLCONTROL_H__

class SkillStateBase;
class CharacterBase;

/**
 * �X�L������.
 */
class SkillControl
{

public:

	// �R���X�g���N�^
	SkillControl(CharacterBase *pInOwner);

	// �f�X�g���N�^
	~SkillControl() {}

	// ���t���[���̏���.
	void Poll(s32 DeltaTime);

	// �g�p.
	void Use(u32 InSkillId, CharacterBase *pInTarget);

	// ���L�҂��擾.
	CharacterBase *GetOwner() const { return pOwner; }

	// �X�L���h�c���擾
	u32 GetSkillId() const { return SkillId; }

	// �^�[�Q�b�g���擾�B
	CharacterBase *GetTarget() const { return pTarget; }

private:

	// State
	SkillStateBase *pState;

	// ���L��.
	CharacterBase *pOwner;

	// �^�[�Q�b�g.
	CharacterBase *pTarget;

	// �X�L���h�c
	u32 SkillId;

};

#endif		// #ifndef __SKILLCONTROL_H__