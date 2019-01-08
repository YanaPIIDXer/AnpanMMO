/**
 * @file PlayerExp.cpp
 * @brief �v���C���[�o���l�N���X
 * @author YanaP
 */
#include "stdafx.h"
#include "PlayerExp.h"

// �R���X�g���N�^
PlayerExp::PlayerExp(int InExp)
	: Exp(InExp)
	, LevelUpExp(100)
{
}

// �ǉ�.
void PlayerExp::Add(u32 Value)
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
