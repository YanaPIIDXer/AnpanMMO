// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BuffBase.h"
#include "Master/BuffMaster.h"

/**
 * �o�t�F�X�s�[�h�A�b�v
 */
class ANPANMMO_API BuffSpeedUp : public BuffBase
{

public:

	// �R���X�g���N�^
	BuffSpeedUp(ACharacterBase *pInCharacter, float InRate);

	// �f�X�g���N�^
	virtual ~BuffSpeedUp() {}

	// �^�C�v���擾.
	virtual uint8 GetType() const override { return BuffItem::SPEEDUP; }

	// �J�n���̏���.
	virtual void Begin() override;

	// �I�����̏���.
	virtual void Finish() override;

private:

	// �ړ����x�{��.
	float Rate;

};
