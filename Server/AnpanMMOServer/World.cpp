#include "stdafx.h"
#include "World.h"
#include "Client.h"

World World::Instance;

// コンストラクタ
World::World()
{
	AnpanMgr.SetSpawnCallback(bind(&World::OnSpawnAnpan, this, _1));
}

// 毎フレームの処理.
void World::Poll()
{
	UpdatePlayerList();

	AnpanMgr.Poll();
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
			It = PlayerList.erase(It);
		}
		else
		{
			++It;
		}
	}
}

// パケットをブロードキャスト
void World::BroadcastPacket(PacketBase *pPacket)
{
	for (int i = 0; i < PlayerList.size(); i++)
	{
		PlayerList[i].lock().get()->GetClient()->SendPacket(pPacket);
	}
}

// アンパンが生成された。
void World::OnSpawnAnpan(AnpanPtr pAnpan)
{
}
