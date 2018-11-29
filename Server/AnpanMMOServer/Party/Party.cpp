#include "stdafx.h"
#include "Party.h"
#include "Client.h"

// �R���X�g���N�^
Party::Party()
	: Uuid(0)
{
}

// �Q��.
void Party::Join(PlayerCharacterPtr pPlayer)
{
	u32 Uuid = pPlayer.lock()->GetClient()->GetUuid();
	if (MemberList.find(Uuid) != MemberList.end()) { return; }		// ���ɎQ���ς݁B
	MemberList[Uuid] = pPlayer;
}

// ���E.
void Party::Secession(u32 Uuid)
{
	if (MemberList.find(Uuid) == MemberList.end()) { return; }			// ���݂��Ȃ��B
	MemberList.erase(Uuid);
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
