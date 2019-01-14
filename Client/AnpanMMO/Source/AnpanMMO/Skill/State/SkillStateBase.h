// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

class SkillControl;

// �X�L���X�e�[�g�^�C�v
enum class ESkillStateType : uint8
{
	// �������Ă��Ȃ�
	Nutral,

	// �L���X�g��.
	Cast,

	// �I�[�g�ړ���.
	AutoMode,
};

/**
 * �X�L���X�e�[�g���N���X
 */
class ANPANMMO_API SkillStateBase
{

public:

	// �R���X�g���N�^
	SkillStateBase(SkillControl *pInControl);

	// �f�X�g���N�^
	virtual ~SkillStateBase() {}

	// State�J�n���̏���.
	virtual void BeginState() {}

	// ���t���[���̏���.
	virtual void Poll() {}

	// �X�e�[�g�^�C�v���擾.
	virtual ESkillStateType GetStateType() = 0;

protected:

	// �X�L������I�u�W�F�N�g���擾.
	SkillControl *GetControl() { return pControl; }

private:

	// �X�L������I�u�W�F�N�g
	SkillControl *pControl;

};
