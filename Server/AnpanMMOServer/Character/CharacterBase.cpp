/**
 * @file CharacterBase.cpp
 * @brief キャラクタ基底クラス
 * @author YanaP
 */
#include "stdafx.h"
#include "CharacterBase.h"
#include "Math/MathUtil.h"
#include "Master/MasterData.h"
#include "Packet/PacketDamage.h"
#include "Packet/PacketHeal.h"
#include "Packet/PacketSkillUseFailed.h"

// コンストラクタ
CharacterBase::CharacterBase()
	: Skill(this)
	, Recast(this)
	, Uuid(0)
	, BuffMgr(this)
{
}

// 毎フレームの処理.
void CharacterBase::Poll(s32 DeltaTime)
{
	Skill.Poll(DeltaTime);
	Recast.Poll(DeltaTime);
	BuffMgr.Poll(DeltaTime);
	
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

// 装備しているか？
bool CharacterBase::IsEquiped(u32 EquipId) const
{
	return ((Parameter.GetRightEquip().GetEquipId() == EquipId) || (Parameter.GetLeftEquip().GetEquipId() == EquipId));
}

// バフ追加
void CharacterBase::AddBuff(u32 BuffId)
{
	BuffMgr.AddBuff(BuffId);
	const BuffItem *pItem = MasterData::GetInstance().GetBuffMaster().GetItem(BuffId);
	if (pItem != NULL && pItem->Type == BuffItem::PARALYSIS)
	{
		// 麻痺を貰った場合はスキルをキャンセル
		Skill.Cancel(PacketSkillUseFailed::Paralysis);
	}
}

// 麻痺状態か？
bool CharacterBase::IsParalysis() const
{
	return BuffMgr.IsActive(BuffItem::PARALYSIS);
}


// 装備切り替え
void CharacterBase::ChangeEquipData(u32 RightEquipId, u32 LeftEquipId)
{
	Parameter.ChangeEquip(RightEquipId, LeftEquipId);
}
