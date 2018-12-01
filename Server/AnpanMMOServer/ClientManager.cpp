#include "stdafx.h"
#include "ClientManager.h"

ClientManager ClientManager::Instance;

// �R���X�g���N�^
ClientManager::ClientManager()
	: NextUuid(1)
{
}

// �������.
void ClientManager::Poll()
{
	MapIterator It = Map.begin();
	while (It != Map.end())
	{
		if (!It->second->IsConnected())
		{
			It = Map.erase(It);
		}
		else
		{
			++It;
		}
	}
}

// �N���C�A���g����.
void ClientManager::CreateClient(const shared_ptr<tcp::socket> &pSocket)
{
	Client *pNewClient = new Client(pSocket);
	ClientSharedPtr pClient = ClientSharedPtr(pNewClient);

	u32 Uuid = NextUuid;
	pClient->SetUuid(Uuid);
	NextUuid++;

	// �}�b�v�ɒǉ��B
	Map[Uuid] = pClient;
}

// �擾.
ClientPtr ClientManager::Get(u32 Uuid)
{
	MapIterator It = Map.find(Uuid);
	if (It == Map.end()) { return ClientPtr(); }
	return It->second;
}

// �J�X�^�}�h�c����擾.
ClientPtr ClientManager::GetFromCustomerId(u32 CustomerId)
{
	for (MapIterator It = Map.begin(); It != Map.end(); ++It)
	{
		if (It->second->GetCustomerId() == CustomerId) { return It->second; }
	}
	return ClientPtr();
}

// �p�P�b�g���o���T���B
void ClientManager::BroadcastPacket(PacketBase *pPacket)
{
	for (MapIterator It = Map.begin(); It != Map.end(); ++It)
	{
		It->second->SendPacket(pPacket);
	}
}
