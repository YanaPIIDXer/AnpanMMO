#include "stdafx.h"
#include "Party.h"
#include "Client.h"
#include "Character/Player/PlayerCharacter.h"
#include "WeakPtrDefine.h"
#include "Packet/PacketPartyJoinMember.h"
#include "Packet/PacketPartyMemberList.h"

const u32 Party::MaximumMember = 4;

// �R���X�g���N�^
Party::Party(u32 InUuid)
	: Uuid(InUuid)
{
}

// �Q��.
bool Party::Join(PlayerCharacterPtr pPlayer)
{
	if (IsMaximumMember()) { return false; }		// �����o�����ő�.
	u32 Uuid = pPlayer.lock()->GetClient()->GetUuid();
	if (MemberList.find(Uuid) != MemberList.end()) { return false; }		// ���ɎQ���ς݁B

	// �����o�ǉ����o���T��
	{
		PartyMemberData Data(Uuid, pPlayer.lock()->GetName());
		PacketPartyJoinMember JoinPacket(Data);
		BroadcastPacket(&JoinPacket);
	}

	MemberList[Uuid] = pPlayer;
	pPlayer.lock()->SetParty(shared_from_this());

	// �����o���X�g�𑗐M.
	PacketPartyMemberList ListPacket;
	for (MemberMap::iterator It = MemberList.begin(); It != MemberList.end(); ++It)
	{
		PartyMemberData Data(It->first, It->second.lock()->GetName());
		if (It->first == Uuid)
		{
			// ���[�_�[�͐擪.
			ListPacket.MemberList.Insert(Data, 0);
		}
		else
		{
			// ����ȊO�͕��ʂ�PushBack
			ListPacket.MemberList.PushBack(Data);
		}
	}
	pPlayer.lock()->GetClient()->SendPacket(&ListPacket);

	return true;
}

// ���E.
void Party::Exit(u32 Uuid)
{
	if (MemberList.find(Uuid) == MemberList.end()) { return; }			// ���݂��Ȃ��B
	MemberList[Uuid].lock()->SetParty(PartyPtr());
	MemberList.erase(Uuid);
}

// �����o���X�g�擾.
std::vector<PlayerCharacterPtr> Party::GetMemberList() const
{
	std::vector<PlayerCharacterPtr> List;
	for (MemberMap::const_iterator It = MemberList.begin(); It != MemberList.end(); ++It)
	{
		List.push_back(It->second);
	}
	return List;
}

// �폜���Ă��������H
bool Party::IsAbleDelete() const
{
	for (MemberMap::const_iterator It = MemberList.begin(); It != MemberList.end(); ++It)
	{
		if (!It->second.expired()) { return false; }
	}

	// �p�[�e�B�����o�S�����������Ă�����폜�B
	return true;
}

// �p�P�b�g���o���T���B
void Party::BroadcastPacket(PacketBase *pPacket)
{
	for (MemberMap::iterator It = MemberList.begin(); It != MemberList.end(); ++It)
	{
		It->second.lock()->GetClient()->SendPacket(pPacket);
	}
}
