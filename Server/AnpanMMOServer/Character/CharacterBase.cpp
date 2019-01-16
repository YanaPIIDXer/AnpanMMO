/**
 * @file CharacterBase.cpp
 * @brief �L�����N�^���N���X
 * @author YanaP
 */
#include "stdafx.h"
#include "CharacterBase.h"
#include "Math/MathUtil.h"
#include "Master/MasterData.h"
#include "Packet/PacketDamage.h"
#include "Packet/PacketHeal.h"
#include "Packet/PacketSkillUseFailed.h"

// �R���X�g���N�^
CharacterBase::CharacterBase()
	: Skill(this)
	, Recast(this)
	, Uuid(0)
	, BuffMgr(this)
{
}

// ���t���[���̏���.
void CharacterBase::Poll(s32 DeltaTime)
{
	Skill.Poll(DeltaTime);
	Recast.Poll(DeltaTime);
	BuffMgr.Poll(DeltaTime);
	
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
void CharacterBase::ApplyDamage(CharacterPtr pAttacker, u32 Value)
{
	Parameter.SubtractHp(Value);

	PacketDamage Packet(GetCharacterType(), Uuid, Value, Parameter.GetHp());
	pArea.lock()->BroadcastPacket(&Packet);

	OnDamaged(pAttacker, Value);
}

// ��.
void CharacterBase::Heal(u32 Value)
{
	Parameter.AddHp(Value);

	PacketHeal Packet(GetCharacterType(), Uuid, Value, Parameter.GetHp());
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
	Parameter.SetHp(Parameter.GetMaxHp());
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

// �������Ă��邩�H
bool CharacterBase::IsEquiped(u32 EquipId) const
{
	return ((Parameter.GetRightEquip().GetEquipId() == EquipId) || (Parameter.GetLeftEquip().GetEquipId() == EquipId));
}

// �o�t�ǉ�
void CharacterBase::AddBuff(u32 BuffId)
{
	BuffMgr.AddBuff(BuffId);
	const BuffItem *pItem = MasterData::GetInstance().GetBuffMaster().GetItem(BuffId);
	if (pItem != NULL && pItem->Type == BuffItem::PARALYSIS)
	{
		// ��Ⴢ������ꍇ�̓X�L�����L�����Z��
		Skill.Cancel(PacketSkillUseFailed::Paralysis);
	}
}

// ��჏�Ԃ��H
bool CharacterBase::IsParalysis() const
{
	return BuffMgr.IsActive(BuffItem::PARALYSIS);
}


// �����؂�ւ�
void CharacterBase::ChangeEquipData(u32 RightEquipId, u32 LeftEquipId)
{
	Parameter.ChangeEquip(RightEquipId, LeftEquipId);
}
