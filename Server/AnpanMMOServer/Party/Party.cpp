#include "stdafx.h"
#include "Party.h"
#include "Client.h"

const u32 Party::MaximumMember = 4;

// コンストラクタ
Party::Party(u32 InUuid)
	: Uuid(InUuid)
{
}

// 参加.
bool Party::Join(PlayerCharacterPtr pPlayer)
{
	if (IsMaximumMember()) { return false; }		// メンバ数が最大.
	u32 Uuid = pPlayer.lock()->GetClient()->GetUuid();
	if (MemberList.find(Uuid) != MemberList.end()) { return false; }		// 既に参加済み。
	MemberList[Uuid] = pPlayer;
	return true;
}

// 離脱.
void Party::Secession(u32 Uuid)
{
	if (MemberList.find(Uuid) == MemberList.end()) { return; }			// 存在しない。
	MemberList.erase(Uuid);
}

// メンバリスト取得.
std::vector<PlayerCharacterPtr> Party::GetMemberList() const
{
	std::vector<PlayerCharacterPtr> List;
	for (MemberMap::const_iterator It = MemberList.begin(); It != MemberList.end(); ++It)
	{
		List.push_back(It->second);
	}
	return List;
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
