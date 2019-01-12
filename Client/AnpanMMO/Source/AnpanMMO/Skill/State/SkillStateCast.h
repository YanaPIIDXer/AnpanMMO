// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SkillStateBase.h"

/**
 * �X�L���X�e�[�g�F�L���X�g��.
 */
class ANPANMMO_API SkillStateCast : public SkillStateBase
{
public:

	// �R���X�g���N�^
	SkillStateCast(SkillControl *pInControl);

	// �f�X�g���N�^
	virtual ~SkillStateCast() {}

	// �X�e�[�g�^�C�v���擾.
	virtual ESkillStateType GetStateType() override { return ESkillStateType::Cast; }

private:

};
