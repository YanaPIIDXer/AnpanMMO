#include "stdafx.h"
#include "CharacterBase.h"
#include "Math/MathUtil.h"

// �R���X�g���N�^
CharacterBase::CharacterBase()
	: Uuid(0)
{
}

// �ړ�.
void CharacterBase::SetPosition(const Vector2D &MoveTarget)
{
	Position = MoveTarget;
}

// ��]��ݒ�.
void CharacterBase::SetRotate(const Rotation &TargetRotation)
{
	Rot = TargetRotation;
}

// �_���[�W
void CharacterBase::ApplyDamage(weak_ptr<CharacterBase> pAttacker, int Value)
{
	Parameter.Hp -= Value;
	if (Parameter.Hp <= 0)
	{
		Parameter.Hp = 0;
	}

	OnDamaged(pAttacker, Value);
}

// ���ʃx�N�g�����擾.
Vector2D CharacterBase::GetCenterVec() const
{
	Vector2D Vec(1.0f, 0.0f);
	Vec = MathUtil::RotateVector(Vec, Rot.Get());
	return Vec;
}
