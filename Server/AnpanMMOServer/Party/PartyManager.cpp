#include "stdafx.h"
#include "PartyManager.h"
#include "Client.h"
#include "ClientManager.h"
#include "Character/Player/PlayerCharacter.h"
#include "Packet/PacketPartyDissolution.h"

PartyManager PartyManager::Instance;

// コンストラクタ
PartyManager::PartyManager()
{
}

// 毎フレームの処理.
void PartyManager::Poll()
{
	for (PartyList::iterator It = Partys.begin(); It != Partys.end();)
	{
		It->second->Poll();
		if (It->second->IsAbleDelete())
		{
			// パーティ消去.
			// 解散パケットをバラ撒く。
			PacketPartyDissolution Packet;
			It->second->BroadcastPacket(&Packet);
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
	Partys[Uuid] = shared_ptr<Party>(pParty);
	pParty->Join(pCreatePlayer);
}

// 解散.
bool PartyManager::Dissolution(u32 Uuid)
{
	if (Partys.find(Uuid) == Partys.end()) { return false; }

	// 解散を通知する。
	// 但し解散した張本人（リーダー）には送信しない。
	ClientPtr pLeaderClient = ClientManager::GetInstance().Get(Uuid);
	PacketPartyDissolution Packet;
	Partys[Uuid]->BroadcastPacket(&Packet, pLeaderClient.lock().get());

	Partys.erase(Uuid);
	return true;
}

// 取得.
PartyPtr PartyManager::Get(u32 Uuid)
{
	if (Partys.find(Uuid) == Partys.end()) { return PartyPtr(); }
	return Partys[Uuid];
}

// 既にどこかのパーティに参加済みか？
bool PartyManager::IsAlreadyJoined(u32 Uuid)
{
	for (PartyList::iterator It = Partys.begin(); It != Partys.end(); ++It)
	{
		std::vector<PlayerCharacterPtr> MemberList = It->second->GetMemberList();
		for (u32 i = 0; i < MemberList.size(); i++)
		{
			if (MemberList[i].lock()->GetClient()->GetUuid() == Uuid) { return true; }
		}
	}
	return false;
}
