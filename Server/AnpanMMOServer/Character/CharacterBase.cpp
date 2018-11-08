#include "stdafx.h"
#include "CharacterBase.h"

// コンストラクタ
CharacterBase::CharacterBase()
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
void CharacterBase::ApplyDamage(int Value)
{
	Parameter.Hp -= Value;
	if (Parameter.Hp <= 0)
	{
		Parameter.Hp = 0;
	}
}
