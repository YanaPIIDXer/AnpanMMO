#include "stdafx.h"
#include "PlayerCharacter.h"

// �R���X�g���N�^
PlayerCharacter::PlayerCharacter(Client *pInClient, int MaxHp, int Atk, int Def)
	: pClient(pInClient)
{
	SetParameter(MaxHp, MaxHp, Atk, Def);
}
