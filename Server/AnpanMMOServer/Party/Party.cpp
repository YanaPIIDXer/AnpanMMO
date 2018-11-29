#include "stdafx.h"
#include "Party.h"
#include "Client.h"
#include "Character/Player/PlayerCharacter.h"
#include "WeakPtrDefine.h"
#include "Packet/PacketPartyJoinMember.h"
#include "Packet/PacketPartyMemberList.h"

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

	// メンバ追加をバラ撒く
	{
		PartyMemberData Data(Uuid, pPlayer.lock()->GetName());
		PacketPartyJoinMember JoinPacket(Data);
		BroadcastPacket(&JoinPacket);
	}

	MemberList[Uuid] = pPlayer;
	pPlayer.lock()->SetParty(shared_from_this());

	// メンバリストを送信.
	PacketPartyMemberList ListPacket;
	for (MemberMap::iterator It = MemberList.begin(); It != MemberList.end(); ++It)
	{
		PartyMemberData Data(It->first, It->second.lock()->GetName());
		if (It->first == Uuid)
		{
			// リーダーは先頭.
			ListPacket.MemberList.Insert(Data, 0);
		}
		else
		{
			// それ以外は普通にPushBack
			ListPacket.MemberList.PushBack(Data);
		}
	}
	pPlayer.lock()->GetClient()->SendPacket(&ListPacket);

	return true;
}

// 離脱.
void Party::Exit(u32 Uuid)
{
	if (MemberList.find(Uuid) == MemberList.end()) { return; }			// 存在しない。
	MemberList[Uuid].lock()->SetParty(PartyPtr());
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

// パケットをバラ撒く。
void Party::BroadcastPacket(PacketBase *pPacket)
{
	for (MemberMap::iterator It = MemberList.begin(); It != MemberList.end(); ++It)
	{
		It->second.lock()->GetClient()->SendPacket(pPacket);
	}
}
