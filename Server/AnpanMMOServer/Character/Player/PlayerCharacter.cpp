#include "stdafx.h"
#include "PlayerCharacter.h"
#include "Client.h"
#include "Math/Random.h"
#include "Packet/PacketLevelUp.h"
#include "Area/AreaManager.h"
#include "CacheServer/CacheServerConnection.h"
#include "Packet/CachePacketCharacterDataSave.h"

// �R���X�g���N�^
PlayerCharacter::PlayerCharacter(Client *pInClient, int MaxHp, int Atk, int Def, int InExp)
	: pClient(pInClient)
	, Exp(InExp)
	, SaveAreaId(0)
	, SavePosition(Vector3D::Zero)
{
	SetParameter(MaxHp, MaxHp, Atk, Def);
	Exp.SetLevelUpCallback(bind(&PlayerCharacter::OnLevelUp, this));
}

// �f�X�g���N�^
PlayerCharacter::~PlayerCharacter()
{
	SaveParameter();
}

// �ړ������B
void PlayerCharacter::OnMoved()
{
	if (GetArea().lock()->IsInstance()) { return; }
	SavePosition = GetPosition();
}

// �G���A���؂�ւ�����B
void PlayerCharacter::OnAreaChange()
{
	AreaPtr pArea = GetArea();
	if (pArea.lock()->IsInstance()) { return; }
	SaveAreaId = pArea.lock()->GetId();
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
	if (SaveAreaId == 0) { return; }		// �܂��G���A�ɑ����Ă��Ȃ��B
	Client *pClient = GetClient();
	CachePacketCharacterDataSave Packet(pClient->GetUuid(), pClient->GetCustomerId(), Param.MaxHp, Param.Atk, Param.Def, Exp.Get(), SaveAreaId, SavePosition.X, SavePosition.Y, SavePosition.Z);
	CacheServerConnection::GetInstance()->SendPacket(&Packet);
}
