#include "stdafx.h"
#include "PlayerCharacter.h"
#include "Client.h"
#include "Math/Random.h"
#include "DBConnection.h"
#include "Packet/PacketLevelUp.h"
#include "Area/AreaManager.h"

// �R���X�g���N�^
PlayerCharacter::PlayerCharacter(Client *pInClient, int MaxHp, int Atk, int Def, int InExp)
	: pClient(pInClient)
	, Exp(InExp)
{
	SetParameter(MaxHp, MaxHp, Atk, Def);
	Exp.SetLevelUpCallback(bind(&PlayerCharacter::OnLevelUp, this));
}

// �f�X�g���N�^
PlayerCharacter::~PlayerCharacter()
{
	SaveParameter();
}


// ���x���A�b�v�R�[���o�b�N
void PlayerCharacter::OnLevelUp()
{
	int MaxHp = Random::Range<int>(10, 20);
	int Atk = Random::Range<int>(10, 20);
	int Def = Random::Range<int>(10, 20);
	AddParameter(MaxHp, Atk, Def);

	const CharacterParameter &Param = GetParameter();
	PacketLevelUp Packet(Param.MaxHp, Param.Atk, Param.Def, Exp.Get());
	GetClient()->SendPacket(&Packet);

	SaveParameter();
}

// �p�����[�^��ۑ�.
void PlayerCharacter::SaveParameter()
{
	const CharacterParameter &Param = GetParameter();
	AreaPtr pArea = GetArea();
	const Vector2D Pos = GetPosition();
	if (!DBConnection::GetInstance().SaveCharacterParameter(GetClient()->GetUuid(), Param.MaxHp, Param.Atk, Param.Def, Exp.Get(), pArea.lock()->GetId(), Pos.X, Pos.Y))
	{
		std::cout << "Parameter Save Failed..." << std::endl;
	}
}
