// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SkillStateBase.h"

/**
 * �X�L���X�e�[�g�F�������Ă��Ȃ��B
 */
class ANPANMMO_API SkillStateNutral : public SkillStateBase
{

public:

	// �R���X�g���N�^
	SkillStateNutral(SkillControl *pInControl);

	// �f�X�g���N�^
	virtual ~SkillStateNutral() {}

	// �X�e�[�g�^�C�v���擾.
	virtual ESkillStateType GetStateType() override { return ESkillStateType::Nutral; }

private:

};
