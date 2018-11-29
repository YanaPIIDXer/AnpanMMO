#include "stdafx.h"
#include "Party.h"
#include "Client.h"

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
	MemberList[Uuid] = pPlayer;
	return true;
}

// ���E.
void Party::Secession(u32 Uuid)
{
	if (MemberList.find(Uuid) == MemberList.end()) { return; }			// ���݂��Ȃ��B
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
