#include "stdafx.h"
#include "CharacterBase.h"

// コンストラクタ
CharacterBase::CharacterBase()
{
}

// 移動.
void CharacterBase::Move(const Vector2D &MoveTarget)
{
	Position = MoveTarget;
}

// 回転を設定.
void CharacterBase::SetRotate(const Rotation &TargetRotation)
{
	Rot = TargetRotation;
}

// 回転.
void CharacterBase::Rotate(float AddRotation)
{
	Rot += AddRotation;
}

// ダメージ
void CharacterBase::ApplyDamage(int Value)
{
	Parameter.Hp -= Value;
	if (Parameter.Hp <= 0)
	{
		Parameter.Hp = 0;
	}
}
