#include "stdafx.h"
#include "World.h"

World World::Instance;

// �R���X�g���N�^
World::World()
{
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
