// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BuffBase.h"

/**
 * �o�t�F�������Ȃ�
 * �N���C�A���g���œ��ɂ�鎖�������ꍇ�͂��̃N���X���g���B
 */
class ANPANMMO_API BuffNop : public BuffBase
{

public:

	// �R���X�g���N�^
	BuffNop(ACharacterBase *pInCharacter, uint8 InType);

	// �f�X�g���N�^
	virtual ~BuffNop() {}

	// �^�C�v���擾.
	virtual uint8 GetType() const override { return Type; }

private:

	// �^�C�v
	uint8 Type;

};
