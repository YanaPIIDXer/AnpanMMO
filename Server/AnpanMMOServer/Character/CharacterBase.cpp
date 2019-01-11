/**
 * @file CharacterBase.cpp
 * @brief キャラクタ基底クラス
 * @author YanaP
 */
#include "stdafx.h"
#include "CharacterBase.h"
#include "Math/MathUtil.h"
#include "Packet/PacketDamage.h"
#include "Packet/PacketHeal.h"

// コンストラクタ
CharacterBase::CharacterBase()
	: Skill(this)
	, Recast(this)
	, Uuid(0)
{
}

// 毎フレームの処理.
void CharacterBase::Poll(s32 DeltaTime)
{
	Skill.Poll(DeltaTime);
	Recast.Poll(DeltaTime);
	
	Update(DeltaTime);
}

// 移動.
void CharacterBase::SetPosition(const Vector3D &MoveTarget)
{
	Position = MoveTarget;
}

// 回転を設定.
void CharacterBase::SetRotate(const Rotation &TargetRotation)
{
	Rot = TargetRotation;
}

// ダメージ
void CharacterBase::ApplyDamage(CharacterPtr pAttacker, u32 Value)
{
	Parameter.SubtractHp(Value);

	PacketDamage Packet(GetCharacterType(), Uuid, Value, Parameter.GetHp());
	pArea.lock()->BroadcastPacket(&Packet);

	OnDamaged(pAttacker, Value);
}

// 回復.
void CharacterBase::Heal(u32 Value)
{
	Parameter.AddHp(Value);

	PacketHeal Packet(GetCharacterType(), Uuid, Value, Parameter.GetHp());
	pArea.lock()->BroadcastPacket(&Packet);
}

// 正面ベクトルを取得.
Vector3D CharacterBase::GetCenterVec() const
{
	Vector3D Vec(1.0f, 0.0f, 0.0f);
	Vec = MathUtil::RotateVector(Vec, Rot.Get());
	return Vec;
}

// 移動.
void CharacterBase::Move(const Vector3D &MoveValue)
{
	Position += MoveValue;
}

// 回転.
void CharacterBase::Rotate(float RotateValue)
{
	Rot.Set(Rot.Get() + RotateValue);
}

// リスポン
void CharacterBase::Respawn()
{
	Parameter.SetHp(Parameter.GetMaxHp());
	Position = Vector3D(0.0f, 0.0f, 0.0f);
}

// スキル使用.
void CharacterBase::UseSkill(u32 SkillId, CharacterPtr pTarget)
{
	Skill.Use(SkillId, pTarget);
}

// リキャスト開始.
void CharacterBase::StartRecast(u32 SkillId)
{
	Recast.Add(SkillId);
}
