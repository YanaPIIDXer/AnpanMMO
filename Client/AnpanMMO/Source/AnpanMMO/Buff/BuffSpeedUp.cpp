// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.


#include "BuffSpeedUp.h"
#include "Character/CharacterBase.h"

// �R���X�g���N�^
BuffSpeedUp::BuffSpeedUp(ACharacterBase *pInCharacter, float InRate)
	: BuffBase(pInCharacter)
	, Rate(InRate)
{
}

// �J�n���̏���.
void BuffSpeedUp::Begin()
{
	GetCharacter()->SetMoveSpeedRate(Rate);
}

// �I�����̏���.
void BuffSpeedUp::Finish()
{
	GetCharacter()->SetMoveSpeedRate(1.0f);
}
