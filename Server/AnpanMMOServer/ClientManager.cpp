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

}

// �N���C�A���g����.
void ClientManager::CreateClient(const shared_ptr<tcp::socket> &pSocket)
{
	ClientSharedPtr pClient = ClientSharedPtr(new Client(pSocket));

	// ���X�g�ɒǉ��B
	ClientList.push_back(pClient);
}
