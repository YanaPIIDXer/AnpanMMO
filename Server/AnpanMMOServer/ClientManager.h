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
	typedef std::vector<ClientSharedPtr> ClientList;
	typedef ClientList::iterator ListIterator;

public:

	// �f�X�g���N�^
	~ClientManager() {}

	// �������.
	void Poll();

	// �N���C�A���g����.
	void CreateClient(const shared_ptr<tcp::socket> &pSocket);

private:

	// �N���C�A���g���X�g
	ClientList List;

	// ======== Singleton ============
public:

	static ClientManager &GetInstance() { return Instance; }

private:

	ClientManager();
	static ClientManager Instance;

};

#endif		// #ifndef __CLIENTMANAGER_H__
