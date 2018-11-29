#include "stdafx.h"
#include "PartyManager.h"

PartyManager PartyManager::Instance;

// �R���X�g���N�^
PartyManager::PartyManager()
	: NextUuid(1)
{
}

// ���t���[���̏���.
void PartyManager::Poll()
{
	for (PartyList::iterator It = Partys.begin(); It != Partys.end(); ++It)
	{
		if (It->second.lock()->IsAbleDelete())
		{
			// �p�[�e�B����.
			It = Partys.erase(It);
		}
		else
		{
			++It;
		}
	}
}

// �ǉ�.
void PartyManager::Add(PartyPtr pParty)
{
	u32 Uuid = NextUuid;
	Partys[Uuid] = pParty;
	pParty.lock()->SetUuid(Uuid);
	NextUuid++;
}
