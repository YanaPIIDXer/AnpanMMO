#include "stdafx.h"
#include "PlayerManager.h"
#include "Client.h"
#include "Packet/PacketSpawnPlayer.h"

// コンストラクタ
PlayerManager::PlayerManager()
{
}

// 毎フレームの処理.
void PlayerManager::Poll()
{
	PlayerMap::iterator It = PlayerList.begin();
	while (It != PlayerList.end())
	{
		if (It->second.expired())
		{
			It = PlayerList.erase(It);
		}
		else
		{
			++It;
		}
	}
}

// 追加.
void PlayerManager::Add(u8 Uuid, PlayerCharacterPtr pPlayer)
{
	PlayerList[Uuid] = pPlayer;

	PacketSpawnPlayer Packet(Uuid);
	BroadcastPacket(&Packet, pPlayer.lock()->GetClient());
}

// 取得.
PlayerCharacterPtr PlayerManager::Get(u8 Uuid) const
{
	PlayerMap::const_iterator It = PlayerList.find(Uuid);
	if (It == PlayerList.end()) { return PlayerCharacterPtr(); }
	return It->second;
}

// パケットをブロードキャスト
void PlayerManager::BroadcastPacket(PacketBase *pPacket, Client *pIgnoreClient)
{
	for (PlayerMap::iterator It = PlayerList.begin(); It != PlayerList.end(); ++It)
	{
		Client *pClient = It->second.lock()->GetClient();
		if (pClient == pIgnoreClient) { continue; }
		pClient->SendPacket(pPacket);
	}
}
