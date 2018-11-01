#ifndef __CLIENTMANAGER_H__
#define __CLIENTMANAGER_H__

#include <vector>
#include "Client.h"

typedef weak_ptr<Client> ClientPtr;

/**
 * �N���C�A���g�Ǘ�.
 */
class ClientManager : noncopyable
{

private:		// �ʖ���`.

	typedef shared_ptr<Client> ClientSharedPtr;

public:

	// �f�X�g���N�^
	~ClientManager() {}

	// �������.
	void Poll();

	// �N���C�A���g����.
	ClientPtr CreateClient(const shared_ptr<tcp::socket> &pSocket);

private:

	// �N���C�A���g���X�g
	std::vector<ClientSharedPtr> ClientList;

	// ======== Singleton ============
public:

	static ClientManager &GetInstance() { return Instance; }

private:

	ClientManager();
	static ClientManager Instance;

};

#endif		// #ifndef __CLIENTMANAGER_H__
