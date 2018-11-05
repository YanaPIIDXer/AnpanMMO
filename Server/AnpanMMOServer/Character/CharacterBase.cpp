#include "stdafx.h"
#include "CharacterBase.h"

// コンストラクタ
CharacterBase::CharacterBase()
{
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
