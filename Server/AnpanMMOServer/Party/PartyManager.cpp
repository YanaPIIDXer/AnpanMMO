#include "stdafx.h"
#include "PartyManager.h"
#include "Client.h"

PartyManager PartyManager::Instance;

// �R���X�g���N�^
PartyManager::PartyManager()
{
}

// ���t���[���̏���.
void PartyManager::Poll()
{
	for (PartyList::iterator It = Partys.begin(); It != Partys.end(); ++It)
	{
		if (It->second->IsAbleDelete())
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

// �쐬.
void PartyManager::Create(PlayerCharacterPtr pCreatePlayer)
{
	u32 Uuid = pCreatePlayer.lock()->GetClient()->GetUuid();
	Party *pParty = new Party(Uuid);
	pParty->Join(pCreatePlayer);
	Partys[Uuid] = shared_ptr<Party>(pParty);
}

// �擾.
PartyPtr PartyManager::Get(u32 Uuid)
{
	if (Partys.find(Uuid) == Partys.end()) { return PartyPtr(); }
	return Partys[Uuid];
}
