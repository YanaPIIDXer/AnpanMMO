#include "stdafx.h"
#include "PlayerCharacter.h"
#include "Client.h"
#include "Math/Random.h"
#include "Packet/PacketLevelUp.h"

// コンストラクタ
PlayerCharacter::PlayerCharacter(Client *pInClient, int MaxHp, int Atk, int Def, int InExp)
	: pClient(pInClient)
	, Exp(InExp)
{
	SetParameter(MaxHp, MaxHp, Atk, Def);
	Exp.SetLevelUpCallback(bind(&PlayerCharacter::OnLevelUp, this));
}


// レベルアップコールバック
void PlayerCharacter::OnLevelUp()
{
	int MaxHp = Random::Range<int>(10, 20);
	int Atk = Random::Range<int>(10, 20);
	int Def = Random::Range<int>(10, 20);
	AddParameter(MaxHp, Atk, Def);

	const CharacterParameter &Param = GetParameter();
	PacketLevelUp Packet(Param.MaxHp, Param.Atk, Param.Def, Exp.Get());
	GetClient()->SendPacket(&Packet);
}
