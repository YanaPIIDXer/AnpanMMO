#include "stdafx.h"
#include "PlayerManager.h"
#include "Client.h"
#include "Packet/PacketSpawnPlayer.h"
#include "Packet/PacketPlayerList.h"

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
	// 生成を接続済みのクライアントにブロードキャスト
	PacketSpawnPlayer Packet(Uuid);
	BroadcastPacket(&Packet, pPlayer.lock()->GetClient());

	// プレイヤーリストを通知.
	PacketPlayerList ListPacket;
	MakeListPacket(ListPacket);
	pPlayer.lock()->GetClient()->SendPacket(&ListPacket);

	PlayerList[Uuid] = pPlayer;
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


// プレイヤーリストパケットを生成.
void PlayerManager::MakeListPacket(PacketPlayerList &Packet)
{
	for (PlayerMap::iterator It = PlayerList.begin(); It != PlayerList.end(); ++It)
	{
		const Vector2D Position = It->second.lock()->GetPosition();
		PlayerData Data(It->first, Position.X, Position.Y);
		Packet.List.PushBack(Data);
	}
}
