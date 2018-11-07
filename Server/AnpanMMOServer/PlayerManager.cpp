#include "stdafx.h"
#include "PlayerManager.h"
#include "Client.h"

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
}

// 取得.
PlayerCharacterPtr PlayerManager::Get(u8 Uuid) const
{
	PlayerMap::const_iterator It = PlayerList.find(Uuid);
	if (It == PlayerList.end()) { return PlayerCharacterPtr(); }
	return It->second;
}

// パケットをブロードキャスト
void PlayerManager::BroadcastPacket(PacketBase *pPacket)
{
	for (PlayerMap::iterator It = PlayerList.begin(); It != PlayerList.end(); ++It)
	{
		It->second.lock()->GetClient()->SendPacket(pPacket);
	}
}
