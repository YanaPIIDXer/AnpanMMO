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
			std::cout << "Erase Player" << std::endl;
			It = PlayerList.erase(It);
		}
		else
		{
			++It;
		}
	}
}
