#ifndef __SKILLCONTROL_H__
#define __SKILLCONTROL_H__

class SkillStateBase;
class CharacterBase;

#include <boost/function.hpp>

/**
 * �X�L������.
 */
class SkillControl
{

private:		// �ʖ���`.

	typedef boost::function<void(void)> OnCastFinishedFunction;
	typedef boost::function<void(u8)> OnCancelFunction;
	typedef boost::function<void(void)> OnActivateFunction;

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

	// �X�e�[�g�ύX.
	void ChangeState(SkillStateBase *pNewState);

	// �L���X�g�����������B
	void CastFinished();

	// �L�����Z��
	void Cancel(u8 Reason);

	// ����.
	void Activate();

	// ��������Ă��邩�H
	bool IsActive() const;

	// �L���X�g�������Ɏ��s�����֐���ݒ�.
	void SetOnCastFinishedFunction(const OnCastFinishedFunction &Func) { OnCastFinishedFunc = Func; }

	// �L�����Z�����Ɏ��s�����֐���ݒ�.
	void SetOnCancelFunction(const OnCancelFunction &Func) { OnCancelFunc = Func; }

	// �������Ɏ��s�����֐���ݒ�.
	void SetOnActivateFunction(const OnActivateFunction &Func) { OnActivateFunc = Func; }

private:

	// State
	SkillStateBase *pState;

	// �O��State
	SkillStateBase *pPrevState;

	// ���L��.
	CharacterBase *pOwner;

	// �^�[�Q�b�g.
	CharacterBase *pTarget;

	// �X�L���h�c
	u32 SkillId;

	// �L���X�g�������Ɏ��s�����֐�.
	OnCastFinishedFunction OnCastFinishedFunc;

	// �L�����Z�����Ɏ��s�����֐�.
	OnCancelFunction OnCancelFunc;

	// �������Ɏ��s�����֐�.
	OnActivateFunction OnActivateFunc;

};

#endif		// #ifndef __SKILLCONTROL_H__
