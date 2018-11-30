#include "stdafx.h"
#include "Party.h"
#include "Client.h"
#include "Character/Player/PlayerCharacter.h"
#include "WeakPtrDefine.h"
#include "Packet/PacketPartyJoinMember.h"
#include "Packet/PacketPartyJoin.h"

const u32 Party::MaximumMember = 4;

// �R���X�g���N�^
Party::Party(u32 InUuid)
	: Uuid(InUuid)
{
}

// ���t���[���̏���.
void Party::Poll()
{
	for (MemberMap::iterator It = MemberList.begin(); It != MemberList.end();)
	{
		if (It->second.expired())
		{
			It = MemberList.erase(It);
		}
		else
		{
			++It;
		}
	}
}

// �Q��.
bool Party::Join(PlayerCharacterPtr pPlayer)
{
	if (IsMaximumMember()) { return false; }		// �����o�����ő�.
	u32 CharacterUuid = pPlayer.lock()->GetClient()->GetUuid();
	if (MemberList.find(CharacterUuid) != MemberList.end()) { return false; }		// ���ɎQ���ς݁B

	// �����o�ǉ����o���T��
	{
		PartyMemberData Data(CharacterUuid, pPlayer.lock()->GetName());
		PacketPartyJoinMember JoinPacket(Data);
		BroadcastPacket(&JoinPacket);
	}

	MemberList[CharacterUuid] = pPlayer;
	pPlayer.lock()->SetParty(shared_from_this());

	// �p�[�e�B�Q���Q���𑗐M.
	PacketPartyJoin JoinPacket;
	JoinPacket.Uuid = Uuid;
	for (MemberMap::iterator It = MemberList.begin(); It != MemberList.end(); ++It)
	{
		PartyMemberData Data(It->first, It->second.lock()->GetName());
		if (It->first == Uuid)
		{
			// ���[�_�[�͐擪.
			JoinPacket.MemberList.Insert(Data, 0);
		}
		else
		{
			// ����ȊO�͕��ʂ�PushBack
			JoinPacket.MemberList.PushBack(Data);
		}
	}
	pPlayer.lock()->GetClient()->SendPacket(&JoinPacket);

	return true;
}

// ���E.
void Party::Exit(u32 PlayerUuid)
{
	if (MemberList.find(PlayerUuid) == MemberList.end()) { return; }			// ���݂��Ȃ��B
	MemberList[PlayerUuid].lock()->SetParty(PartyPtr());
	MemberList.erase(PlayerUuid);
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
	// ���[�_�[�������Ă�����폜��.
	return (MemberList.find(Uuid) == MemberList.end());
}

// �p�P�b�g���o���T���B
void Party::BroadcastPacket(PacketBase *pPacket, Client *pIgnoreClient)
{
	for (MemberMap::iterator It = MemberList.begin(); It != MemberList.end(); ++It)
	{
		if (It->second.lock()->GetClient() == pIgnoreClient) { continue; }
		It->second.lock()->GetClient()->SendPacket(pPacket);
	}
}
