#include "stdafx.h"
#include "Party.h"
#include "Client.h"
#include "Character/Player/PlayerCharacter.h"
#include "WeakPtrDefine.h"
#include "Packet/PacketPartyJoinMember.h"
#include "Packet/PacketPartyJoin.h"
#include "Packet/PacketPartyExit.h"

const u32 Party::MaximumMember = 4;

// コンストラクタ
Party::Party(u32 InUuid)
	: Uuid(InUuid)
{
}

// 毎フレームの処理.
void Party::Poll()
{
	for (MemberMap::iterator It = MemberList.begin(); It != MemberList.end();)
	{
		if (It->second.expired())
		{
			u32 EraseUuid = It->first;
			It = MemberList.erase(It);
			if (EraseUuid != Uuid)
			{
				// リーダー以外が抜けた場合は離脱パケットをバラ撒く。
				// ※リーダーが抜けた場合はこの後解散パケットがバラ撒かれるので不要。
				PacketPartyExit Packet(EraseUuid);
				BroadcastPacket(&Packet);
			}
		}
		else
		{
			++It;
		}
	}
}

// 参加.
bool Party::Join(PlayerCharacterPtr pPlayer)
{
	if (IsMaximumMember()) { return false; }		// メンバ数が最大.
	u32 CharacterUuid = pPlayer.lock()->GetClient()->GetUuid();
	if (MemberList.find(CharacterUuid) != MemberList.end()) { return false; }		// 既に参加済み。

	// メンバ追加をバラ撒く
	{
		PartyMemberData Data(CharacterUuid, pPlayer.lock()->GetName());
		PacketPartyJoinMember JoinPacket(Data);
		BroadcastPacket(&JoinPacket);
	}

	MemberList[CharacterUuid] = pPlayer;
	pPlayer.lock()->SetParty(shared_from_this());

	// パーティ参加参加を送信.
	PacketPartyJoin JoinPacket;
	JoinPacket.Uuid = Uuid;
	for (MemberMap::iterator It = MemberList.begin(); It != MemberList.end(); ++It)
	{
		PartyMemberData Data(It->first, It->second.lock()->GetName());
		if (It->first == Uuid)
		{
			// リーダーは先頭.
			JoinPacket.MemberList.Insert(Data, 0);
		}
		else
		{
			// それ以外は普通にPushBack
			JoinPacket.MemberList.PushBack(Data);
		}
	}
	pPlayer.lock()->GetClient()->SendPacket(&JoinPacket);

	return true;
}

// 離脱.
void Party::Exit(u32 PlayerUuid)
{
	if (MemberList.find(PlayerUuid) == MemberList.end()) { return; }			// 存在しない。
	MemberList[PlayerUuid].lock()->SetParty(PartyPtr());
	MemberList.erase(PlayerUuid);
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
	// リーダーが抜けていたら削除可.
	return (MemberList.find(Uuid) == MemberList.end());
}

// パケットをバラ撒く。
void Party::BroadcastPacket(PacketBase *pPacket, Client *pIgnoreClient)
{
	for (MemberMap::iterator It = MemberList.begin(); It != MemberList.end(); ++It)
	{
		if (It->second.lock()->GetClient() == pIgnoreClient) { continue; }
		It->second.lock()->GetClient()->SendPacket(pPacket);
	}
}
