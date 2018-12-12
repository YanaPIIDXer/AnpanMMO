#include "stdafx.h"
#include "CharacterBase.h"
#include "Math/MathUtil.h"
#include "Packet/PacketDamage.h"
#include "Packet/PacketHeal.h"

// �R���X�g���N�^
CharacterBase::CharacterBase()
	: Skill(this)
	, Recast(this)
	, Uuid(0)
{
}

// ���t���[���̏���.
void CharacterBase::Poll(s32 DeltaTime)
{
	Skill.Poll(DeltaTime);
	Recast.Poll(DeltaTime);
	
	Update(DeltaTime);
}

// �ړ�.
void CharacterBase::SetPosition(const Vector3D &MoveTarget)
{
	Position = MoveTarget;
}

// ��]��ݒ�.
void CharacterBase::SetRotate(const Rotation &TargetRotation)
{
	Rot = TargetRotation;
}

// �_���[�W
void CharacterBase::ApplyDamage(CharacterPtr pAttacker, int Value)
{
	Parameter.Hp -= Value;
	if (Parameter.Hp <= 0)
	{
		Parameter.Hp = 0;
	}

	PacketDamage Packet(GetCharacterType(), Uuid, Value, Parameter.Hp);
	pArea.lock()->BroadcastPacket(&Packet);

	OnDamaged(pAttacker, Value);
}

// ��.
void CharacterBase::Heal(int Value)
{
	Parameter.Hp += Value;
	if (Parameter.Hp > Parameter.MaxHp)
	{
		Parameter.Hp = Parameter.MaxHp;
	}

	PacketHeal Packet(GetCharacterType(), Uuid, Value, Parameter.Hp);
	pArea.lock()->BroadcastPacket(&Packet);
}

// ���ʃx�N�g�����擾.
Vector3D CharacterBase::GetCenterVec() const
{
	Vector3D Vec(1.0f, 0.0f, 0.0f);
	Vec = MathUtil::RotateVector(Vec, Rot.Get());
	return Vec;
}

// �ړ�.
void CharacterBase::Move(const Vector3D &MoveValue)
{
	Position += MoveValue;
}

// ��].
void CharacterBase::Rotate(float RotateValue)
{
	Rot.Set(Rot.Get() + RotateValue);
}

// ���X�|��
void CharacterBase::Respawn()
{
	Parameter.Hp = Parameter.MaxHp;
	Position = Vector3D(0.0f, 0.0f, 0.0f);
}

// �X�L���g�p.
void CharacterBase::UseSkill(u32 SkillId, CharacterPtr pTarget)
{
	Skill.Use(SkillId, pTarget);
}

// ���L���X�g�J�n.
void CharacterBase::StartRecast(u32 SkillId)
{
	Recast.Add(SkillId);
}
