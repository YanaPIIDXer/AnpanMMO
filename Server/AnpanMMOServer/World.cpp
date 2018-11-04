#include "stdafx.h"
#include "World.h"

World World::Instance;

// コンストラクタ
World::World()
{
}

// 毎フレームの処理.
void World::Poll()
{
	UpdatePlayerList();
}

// プレイヤーキャラの追加.
void World::AddPlayerCharacter(const PlayerCharacterPtr &pPlayer)
{
	PlayerList.push_back(pPlayer);
}


// PlayerListの更新.
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
