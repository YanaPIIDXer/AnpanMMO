#include "stdafx.h"
#include "CharacterBase.h"

// �R���X�g���N�^
CharacterBase::CharacterBase()
{
}

// �_���[�W
void CharacterBase::ApplyDamage(int Value)
{
	Parameter.Hp -= Value;
	if (Parameter.Hp <= 0)
	{
		Parameter.Hp = 0;
	}
}
