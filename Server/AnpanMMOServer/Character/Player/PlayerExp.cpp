#include "stdafx.h"
#include "PlayerExp.h"

const int PlayerExp::LevelUpExp = 100;

// コンストラクタ
PlayerExp::PlayerExp(int InExp)
	: Exp(InExp)
{
}

// 追加.
void PlayerExp::Add(int Value)
{
	Exp += Value;
	while (Exp >= LevelUpExp)
	{
		// レベルアップ
		Exp -= LevelUpExp;
		if (LevelUpCallback)
		{
			LevelUpCallback();
		}
	}
}
