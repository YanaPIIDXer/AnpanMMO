#include "stdafx.h"
#include "Party.h"
#include "Client.h"

// コンストラクタ
Party::Party()
	: Uuid(0)
{
}

// 参加.
void Party::Join(PlayerCharacterPtr pPlayer)
{
	u32 Uuid = pPlayer.lock()->GetClient()->GetUuid();
	if (MemberList.find(Uuid) != MemberList.end()) { return; }		// 既に参加済み。
	MemberList[Uuid] = pPlayer;
}

// 離脱.
void Party::Secession(u32 Uuid)
{
	if (MemberList.find(Uuid) == MemberList.end()) { return; }			// 存在しない。
	MemberList.erase(Uuid);
}

// 削除してもいいか？
bool Party::IsAbleDelete() const
{
	for (MemberMap::const_iterator It = MemberList.begin(); It != MemberList.end(); ++It)
	{
		if (!It->second.expired()) { return false; }
	}

	// パーティメンバ全員が消失していたら削除可。
	return true;
}
