#include "stdafx.h"
#include "CharacterBase.h"
#include "Math/MathUtil.h"

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

	OnDamaged(pAttacker, Value);
}

// 正面ベクトルを取得.
Vector2D CharacterBase::GetCenterVec() const
{
	Vector2D Vec(1.0f, 0.0f);
	Vec = MathUtil::RotateVector(Vec, Rot.Get());
	return Vec;
}
