#include "stdafx.h"
#include "CharacterBase.h"

// �R���X�g���N�^
CharacterBase::CharacterBase()
{
}

// �ړ�.
void CharacterBase::Move(float X, float Y, float Rotation)
{
	Position.X = X;
	Position.Y = Y;
	Rot.Set(Rotation);
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
