#include "stdafx.h"
#include "World.h"
#include "Client.h"
#include "Packet/PacketSpawnAnpan.h"
#include "Packet/PacketAnpanList.h"

World World::Instance;

// �R���X�g���N�^
World::World()
{
}

// ������.
void World::Initialize()
{
	AnpanMgr.SetSpawnCallback(bind(&World::OnSpawnAnpan, this, _1, _2));
}

// ���t���[���̏���.
void World::Poll()
{
	UpdatePlayerList();

	AnpanMgr.Poll();
}

// �v���C���[�L�����̒ǉ�.
void World::AddPlayerCharacter(const PlayerCharacterPtr &pPlayer)
{
	PlayerList.push_back(pPlayer);

	// �A���p�����X�g��ʒm.
	PacketAnpanList Packet;
	AnpanMgr.MakeListPacket(Packet);

	pPlayer.lock()->GetClient()->SendPacket(&Packet);
}


// PlayerList�̍X�V.
void World::UpdatePlayerList()
{
	std::vector<PlayerCharacterPtr>::iterator It = PlayerList.begin();
	while (It != PlayerList.end())
	{
		if (!It->expired())
		{
			It = PlayerList.erase(It);
		}
		else
		{
			++It;
		}
	}
}

// �p�P�b�g���u���[�h�L���X�g
void World::BroadcastPacket(PacketBase *pPacket)
{
	for (int i = 0; i < PlayerList.size(); i++)
	{
		PlayerList[i].lock().get()->GetClient()->SendPacket(pPacket);
	}
}

// �A���p�����������ꂽ�B
void World::OnSpawnAnpan(unsigned int Uuid, AnpanPtr pAnpan)
{
	const CharacterParameter &Param = pAnpan.lock()->GetParameter();
	const Vector2D &Position = pAnpan.lock()->GetPosition();
	AnpanData Data(Uuid, Position.X, Position.Y, Param.Hp, Param.MaxHp);
	PacketSpawnAnpan Packet(Data);
	BroadcastPacket(&Packet);
}
