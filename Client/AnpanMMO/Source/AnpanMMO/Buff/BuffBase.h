// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

class ACharacterBase;

/**
 * �o�t���N���X
 */
class ANPANMMO_API BuffBase
{

public:

	// �R���X�g���N�^
	BuffBase(ACharacterBase *pInCharacter);

	// �f�X�g���N�^
	virtual ~BuffBase() {}

	// �^�C�v���擾.
	virtual uint8 GetType() const = 0;

	// �J�n���̏���.
	virtual void Begin() {}

	// �I�����̏���.
	virtual void Finish() {}

protected:

	// �L�����N�^�擾.
	ACharacterBase *GetCharacter() { return pCharacter.Get(); }

private:

	// �L�����N�^
	TWeakObjectPtr<ACharacterBase> pCharacter;

};
