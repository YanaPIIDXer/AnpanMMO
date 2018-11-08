#include "stdafx.h"
#include "CharacterBase.h"

// �R���X�g���N�^
CharacterBase::CharacterBase()
{
}

// �ړ�.
void CharacterBase::Move(const Vector2D &MoveTarget)
{
	Position = MoveTarget;
}

// ��]��ݒ�.
void CharacterBase::SetRotate(const Rotation &TargetRotation)
{
	Rot = TargetRotation;
}

// ��].
void CharacterBase::Rotate(float AddRotation)
{
	Rot += AddRotation;
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
