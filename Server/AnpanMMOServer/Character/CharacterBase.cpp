#include "stdafx.h"
#include "CharacterBase.h"
#include "World.h"
#include "Math/MathUtil.h"
#include "Packet/PacketDamage.h"

// コンストラクタ
CharacterBase::CharacterBase()
	: Uuid(0)
{
}

// 移動.
void CharacterBase::SetPosition(const Vector2D &MoveTarget)
{
	Position = MoveTarget;
}

// 回転を設定.
void CharacterBase::SetRotate(const Rotation &TargetRotation)
{
	Rot = TargetRotation;
}

// ダメージ
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

// 正面ベクトルを取得.
Vector2D CharacterBase::GetCenterVec() const
{
	Vector2D Vec(1.0f, 0.0f);
	Vec = MathUtil::RotateVector(Vec, Rot.Get());
	return Vec;
}

// 移動.
void CharacterBase::Move(const Vector2D &MoveValue)
{
	Position += MoveValue;
}

// 回転.
void CharacterBase::Rotate(float RotateValue)
{
	Rot.Set(Rot.Get() + RotateValue);
}
