#include "stdafx.h"
#include "ClientManager.h"

ClientManager ClientManager::Instance;

// �R���X�g���N�^
ClientManager::ClientManager()
{
}

// �������.
void ClientManager::Poll()
{
	ListIterator It = List.begin();
	while (It != List.end())
	{
		if (!It->get()->IsConnected())
		{
			It = List.erase(It);
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
	ClientSharedPtr pClient = ClientSharedPtr(new Client(pSocket));

	// ���X�g�ɒǉ��B
	List.push_back(pClient);
}
