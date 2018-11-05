#include "stdafx.h"
#include "PlayerCharacter.h"

// コンストラクタ
PlayerCharacter::PlayerCharacter(Client *pInClient, int MaxHp, int Atk, int Def)
	: pClient(pInClient)
{
	SetParameter(MaxHp, MaxHp, Atk, Def);
}
