#include "stdafx.h"
#include "World.h"
#include "Client.h"
#include "Packet/PacketSpawnAnpan.h"

World World::Instance;

// コンストラクタ
World::World()
{
}

// 初期化.
void World::Initialize()
{
	AnpanMgr.SetSpawnCallback(bind(&World::OnSpawnAnpan, this, _1, _2));
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
void World::OnSpawnAnpan(unsigned int Uuid, AnpanPtr pAnpan)
{
	const CharacterParameter &Param = pAnpan.lock().get()->GetParameter();
	AnpanData Data(Uuid, Param.Hp, Param.MaxHp);
	PacketSpawnAnpan Packet(Data);
	BroadcastPacket(&Packet);
}
