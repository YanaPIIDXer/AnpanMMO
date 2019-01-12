// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SkillStateBase.h"

class ACharacterBase;

/**
 * �X�L���X�e�[�g�F�I�[�g�ړ���.
 */
class ANPANMMO_API SkillStateAutoMove : public SkillStateBase
{

public:

	// �R���X�g���N�^
	SkillStateAutoMove(SkillControl *pInControl);

	// �f�X�g���N�^
	virtual ~SkillStateAutoMove() {}

	// State�J�n���̏���.
	virtual void BeginState() override;

	// ���t���[���̏���.
	virtual void Poll() override;

	// �X�e�[�g�^�C�v���擾.
	virtual ESkillStateType GetStateType() override { return ESkillStateType::AutoMode; }

private:

	// ���L��.
	TWeakObjectPtr<ACharacterBase> pOwner;

	// �^�[�Q�b�g
	TWeakObjectPtr<ACharacterBase> pTarget;

	// ����.
	float Distance;

	// �ړ��p�P�b�g�𑗂������H
	bool bSendMovePacket;

};
