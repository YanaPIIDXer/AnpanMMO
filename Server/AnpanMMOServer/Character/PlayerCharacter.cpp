#include "stdafx.h"
#include "PlayerCharacter.h"

// �R���X�g���N�^
PlayerCharacter::PlayerCharacter(Client *pInClient, int MaxHp, int Atk, int Def, int InExp)
	: pClient(pInClient)
	, Exp(InExp)
{
	SetParameter(MaxHp, MaxHp, Atk, Def);
}
