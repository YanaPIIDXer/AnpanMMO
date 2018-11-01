#ifndef __CLIENTMANAGER_H__
#define __CLIENTMANAGER_H__

#include <vector>
#include "Client.h"

typedef weak_ptr<Client> ClientPtr;

/**
 * �N���C�A���g�Ǘ�.
 */
class ClientManager
{

private:		// �ʖ���`.

	typedef shared_ptr<Client> ClientSharedPtr;

public:

	// �R���X�g���N�^
	ClientManager();

	// �f�X�g���N�^
	~ClientManager() {}

private:

	// �N���C�A���g���X�g
	std::vector<ClientSharedPtr> ClientList;

};

#endif		// #ifndef __CLIENTMANAGER_H__
