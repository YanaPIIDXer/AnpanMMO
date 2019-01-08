/**
 * @file PlayerExp.cpp
 * @brief プレイヤー経験値クラス
 * @author YanaP
 */
#include "stdafx.h"
#include "PlayerExp.h"

// コンストラクタ
PlayerExp::PlayerExp(int InExp)
	: Exp(InExp)
	, LevelUpExp(100)
{
}

// 追加.
void PlayerExp::Add(u32 Value)
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
