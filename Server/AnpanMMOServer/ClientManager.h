#ifndef __CLIENTMANAGER_H__
#define __CLIENTMANAGER_H__

#include <boost/unordered_map.hpp>
#include "Client.h"
#include "WeakPtrDefine.h"

/**
 * �N���C�A���g�Ǘ�.
 */
class ClientManager : noncopyable
{

private:		// �ʖ���`.

	typedef shared_ptr<Client> ClientSharedPtr;
	typedef unordered_map<u32, ClientSharedPtr> ClientMap;
	typedef ClientMap::iterator MapIterator;

public:

	// �f�X�g���N�^
	~ClientManager() {}

	// �������.
	void Poll();

	// �N���C�A���g����.
	void CreateClient(const shared_ptr<tcp::socket> &pSocket);

	// �擾.
	ClientPtr Get(u32 Uuid);

	// �J�X�^�}�h�c����擾.
	ClientPtr GetFromCustomerId(u32 CustomerId);

private:

	// �N���C�A���g���X�g
	ClientMap Map;

	// ���Ɋ���U��UUID
	u32 NextUuid;

	// ======== Singleton ============
public:

	static ClientManager &GetInstance() { return Instance; }

private:

	ClientManager();
	static ClientManager Instance;

};

#endif		// #ifndef __CLIENTMANAGER_H__
