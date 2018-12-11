// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Master/SkillMaster.h"

class SkillStateBase;
class ACharacterBase;

/**
 * �X�L������N���X
 */
class ANPANMMO_API SkillControl
{

public:

	// �R���X�g���N�^
	SkillControl();

	// �f�X�g���N�^
	~SkillControl();

	// ���t���[���̏���.
	void Poll();

	// ���L�҂�ݒ�.
	void SetOwner(ACharacterBase *pInOwner) { pOwner = pInOwner; }
	
	// �X�L���g�p.
	void UseSkill(uint32 SkillId, ACharacterBase *pInTarget);

	// �L���X�g����������.
	void OnCastFinished();

	// �X�L�������������B
	void OnActivate();

	// ���L�҂��擾.
	TWeakObjectPtr<ACharacterBase> GetOwner() const { return pOwner; }

	// �^�[�Q�b�g���擾.
	TWeakObjectPtr<ACharacterBase> GetTarget() const { return pTarget; }

	// �X�L���f�[�^���擾.
	const SkillItem &GetSkillData() const { return SkillData; }

	// �������Ă��邩�H
	bool IsActive() const;

private:

	// ���݂�State
	SkillStateBase *pState;

	// �O��State
	SkillStateBase *pPrevState;

	// ���L��.
	TWeakObjectPtr<ACharacterBase> pOwner;

	// �^�[�Q�b�g
	TWeakObjectPtr<ACharacterBase> pTarget;

	// �X�L���f�[�^
	SkillItem SkillData;


	// State�؂�ւ�
	void ChangeState(SkillStateBase *pNewState);

};
