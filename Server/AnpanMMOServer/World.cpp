#include "stdafx.h"
#include "World.h"
#include "Client.h"

World World::Instance;

// �R���X�g���N�^
World::World()
{
	AnpanMgr.SetSpawnCallback(bind(&World::OnSpawnAnpan, this, _1));
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
void World::OnSpawnAnpan(AnpanPtr pAnpan)
{
}
