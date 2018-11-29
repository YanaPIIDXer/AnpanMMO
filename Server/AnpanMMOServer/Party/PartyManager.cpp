#include "stdafx.h"
#include "PartyManager.h"
#include "Client.h"

PartyManager PartyManager::Instance;

// コンストラクタ
PartyManager::PartyManager()
{
}

// 毎フレームの処理.
void PartyManager::Poll()
{
	for (PartyList::iterator It = Partys.begin(); It != Partys.end(); ++It)
	{
		if (It->second->IsAbleDelete())
		{
			// パーティ消去.
			It = Partys.erase(It);
		}
		else
		{
			++It;
		}
	}
}

// 作成.
void PartyManager::Create(PlayerCharacterPtr pCreatePlayer)
{
	u32 Uuid = pCreatePlayer.lock()->GetClient()->GetUuid();
	Party *pParty = new Party(Uuid);
	pParty->Join(pCreatePlayer);
	Partys[Uuid] = shared_ptr<Party>(pParty);
}

// 取得.
PartyPtr PartyManager::Get(u32 Uuid)
{
	if (Partys.find(Uuid) == Partys.end()) { return PartyPtr(); }
	return Partys[Uuid];
}
