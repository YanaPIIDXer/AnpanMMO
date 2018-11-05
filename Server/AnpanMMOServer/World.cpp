#include "stdafx.h"
#include "World.h"
#include "Client.h"
#include "Math/DamageCalcUnit.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "Packet/Packet1SpawnAnpan.h"
#include "Packet/PacketAnpanList.h"
#include "Packet/PacketAttack.h"

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

	// アンパンリストを通知.
	PacketAnpanList Packet;
	AnpanMgr.MakeListPacket(Packet);

	pPlayer.lock()->GetClient()->SendPacket(&Packet);
}

// 攻撃を受信した。
void World::OnRecvAttack(Client *pClient, MemoryStreamInterface *pStream)
{
	PacketAttack Packet;
	Packet.Serialize(pStream);

}


// PlayerListの更新.
void World::UpdatePlayerList()
{
	std::vector<PlayerCharacterPtr>::iterator It = PlayerList.begin();
	while (It != PlayerList.end())
	{
		if (It->expired())
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
	const CharacterParameter &Param = pAnpan.lock()->GetParameter();
	const Vector2D &Position = pAnpan.lock()->GetPosition();
	AnpanData Data(Uuid, Position.X, Position.Y, Param.Hp, Param.MaxHp);
	PacketSpawnAnpan Packet(Data);
	BroadcastPacket(&Packet);
}
