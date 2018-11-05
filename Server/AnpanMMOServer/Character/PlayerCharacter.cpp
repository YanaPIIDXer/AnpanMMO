#include "stdafx.h"
#include "PlayerCharacter.h"

// �R���X�g���N�^
PlayerCharacter::PlayerCharacter(Client *pInClient, int MaxHp, int Atk, int Def, int InExp)
	: pClient(pInClient)
	, Exp(InExp)
{
	SetParameter(MaxHp, MaxHp, Atk, Def);
	Exp.SetLevelUpCallback(bind(&PlayerCharacter::OnLevelUp, this));
}


// ���x���A�b�v�R�[���o�b�N
void PlayerCharacter::OnLevelUp()
{

}
