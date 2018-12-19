#ifndef __SKILLCONTROL_H__
#define __SKILLCONTROL_H__

#include <boost/function.hpp>
#include "WeakPtrDefine.h"

class SkillStateBase;

/**
 * �X�L������.
 */
class SkillControl
{

private:		// �ʖ���`.

	typedef boost::function<void(u8)> OnCancelFunction;

	typedef boost::function<void(u32)> OnUsedItemFunction;

	typedef boost::function<void(CharacterBase *)> OnKilledFunction;

public:

	// �R���X�g���N�^
	SkillControl(CharacterBase *pInOwner);

	// �f�X�g���N�^
	~SkillControl();

	// ���t���[���̏���.
	void Poll(s32 DeltaTime);

	// �g�p.
	void Use(u32 InSkillId, CharacterPtr pInTarget);

	// �A�C�e���g�p.
	void UseItem(u32 InItemId, CharacterPtr pInTarget);

	// ���L�҂��擾.
	CharacterBase *GetOwner() const { return pOwner; }

	// �X�L���h�c���擾
	u32 GetSkillId() const { return SkillId; }

	// �^�[�Q�b�g���擾�B
	CharacterPtr GetTarget() const { return pTarget; }

	// �L���X�g�����������B
	void CastFinished();

	// �L�����Z��
	void Cancel(u8 Reason);

	// ����.
	void Activate();

	// ��������Ă��邩�H
	bool IsActive() const;

	// �L���X�g�����H
	bool IsCasting() const;

	// �L�����Z�����Ɏ��s�����֐���ݒ�.
	void SetOnCancelFunction(const OnCancelFunction &Func) { OnCancelFunc = Func; }

	// �A�C�e���g�p��Ɏ��s�����֐���ݒ�.
	void SetOnUsedItemFunction(const OnUsedItemFunction &Func) { OnUsedItemFunc = Func; }

	// �E�Q��Ɏ��s�����֐���ݒ�.
	void SetOnKilledFunction(const OnKilledFunction &Func) { OnKilledFunc = Func; }

private:

	// State
	SkillStateBase *pState;

	// �O��State
	SkillStateBase *pPrevState;

	// ���L��.
	CharacterBase *pOwner;

	// �^�[�Q�b�g.
	CharacterPtr pTarget;

	// �X�L���h�c
	u32 SkillId;

	// �A�C�e���h�c
	u32 ItemId;

	// �L�����Z�����Ɏ��s�����֐�.
	OnCancelFunction OnCancelFunc;

	// �A�C�e���g�p��Ɏ��s�����֐�.
	OnUsedItemFunction OnUsedItemFunc;

	// �E�Q��Ɏ��s�����֐�.
	OnKilledFunction OnKilledFunc;

	// �X�e�[�g�ύX.
	void ChangeState(SkillStateBase *pNewState);

};

#endif		// #ifndef __SKILLCONTROL_H__
