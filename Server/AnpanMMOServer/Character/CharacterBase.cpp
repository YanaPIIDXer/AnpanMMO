#include "stdafx.h"
#include "CharacterBase.h"
#include "World.h"
#include "Math/MathUtil.h"
#include "Packet/PacketDamage.h"

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

	PacketDamage Packet(GetCharacterType(), Uuid, Value, Parameter.Hp);
	World::GetInstance().BroadcastPacket(&Packet);

	OnDamaged(pAttacker, Value);
}

// ���ʃx�N�g�����擾.
Vector2D CharacterBase::GetCenterVec() const
{
	Vector2D Vec(1.0f, 0.0f);
	Vec = MathUtil::RotateVector(Vec, Rot.Get());
	return Vec;
}

// �ړ�.
void CharacterBase::Move(const Vector2D &MoveValue)
{
	Position += MoveValue;
}

// ��].
void CharacterBase::Rotate(float RotateValue)
{
	Rot.Set(Rot.Get() + RotateValue);
}
