#include "stdafx.h"
#include "CharacterBase.h"

// コンストラクタ
CharacterBase::CharacterBase()
{
}

// 移動.
void CharacterBase::Move(float X, float Y, float Rotation)
{
	Position.X = X;
	Position.Y = Y;
	Rot.Set(Rotation);
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
