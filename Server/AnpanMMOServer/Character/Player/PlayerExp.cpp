#include "stdafx.h"
#include "PlayerExp.h"

const int PlayerExp::LevelUpExp = 100;

// �R���X�g���N�^
PlayerExp::PlayerExp(int InExp)
	: Exp(InExp)
{
}

// �ǉ�.
void PlayerExp::Add(int Value)
{
	Exp += Value;
	while (Exp >= LevelUpExp)
	{
		// ���x���A�b�v
		Exp -= LevelUpExp;
		if (LevelUpCallback)
		{
			LevelUpCallback();
		}
	}
}
