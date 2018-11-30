#include "stdafx.h"
#include "PartyManager.h"
#include "Client.h"
#include "ClientManager.h"
#include "Character/Player/PlayerCharacter.h"
#include "Packet/PacketPartyDissolution.h"

PartyManager PartyManager::Instance;

// �R���X�g���N�^
PartyManager::PartyManager()
{
}

// ���t���[���̏���.
void PartyManager::Poll()
{
	for (PartyList::iterator It = Partys.begin(); It != Partys.end();)
	{
		It->second->Poll();
		if (It->second->IsAbleDelete())
		{
			// �p�[�e�B����.
			// ���U�p�P�b�g���o���T���B
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

// �쐬.
void PartyManager::Create(PlayerCharacterPtr pCreatePlayer)
{
	u32 Uuid = pCreatePlayer.lock()->GetClient()->GetUuid();
	Party *pParty = new Party(Uuid);
	Partys[Uuid] = shared_ptr<Party>(pParty);
	pParty->Join(pCreatePlayer);
}

// ���U.
bool PartyManager::Dissolution(u32 Uuid)
{
	if (Partys.find(Uuid) == Partys.end()) { return false; }

	// ���U��ʒm����B
	// �A�����U�������{�l�i���[�_�[�j�ɂ͑��M���Ȃ��B
	ClientPtr pLeaderClient = ClientManager::GetInstance().Get(Uuid);
	PacketPartyDissolution Packet;
	Partys[Uuid]->BroadcastPacket(&Packet, pLeaderClient.lock().get());

	Partys.erase(Uuid);
	return true;
}

// �擾.
PartyPtr PartyManager::Get(u32 Uuid)
{
	if (Partys.find(Uuid) == Partys.end()) { return PartyPtr(); }
	return Partys[Uuid];
}

// ���ɂǂ����̃p�[�e�B�ɎQ���ς݂��H
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
