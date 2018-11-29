#include "stdafx.h"
#include "PartyManager.h"

PartyManager PartyManager::Instance;

// コンストラクタ
PartyManager::PartyManager()
	: NextUuid(1)
{
}

// 毎フレームの処理.
void PartyManager::Poll()
{
	for (PartyList::iterator It = Partys.begin(); It != Partys.end(); ++It)
	{
		if (It->second.lock()->IsAbleDelete())
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

// 追加.
void PartyManager::Add(PartyPtr pParty)
{
	u32 Uuid = NextUuid;
	Partys[Uuid] = pParty;
	pParty.lock()->SetUuid(Uuid);
	NextUuid++;
}
