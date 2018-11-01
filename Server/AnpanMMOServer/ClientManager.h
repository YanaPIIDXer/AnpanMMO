#ifndef __CLIENTMANAGER_H__
#define __CLIENTMANAGER_H__

#include <vector>
#include "Client.h"

typedef weak_ptr<Client> ClientPtr;

/**
 * クライアント管理.
 */
class ClientManager : noncopyable
{

private:		// 別名定義.

	typedef shared_ptr<Client> ClientSharedPtr;

public:

	// デストラクタ
	~ClientManager() {}

	// 定期処理.
	void Poll();

private:

	// クライアントリスト
	std::vector<ClientSharedPtr> ClientList;

	// ======== Singleton ============
public:

	static ClientManager &GetInstance() { return Instance; }

private:

	ClientManager();
	static ClientManager Instance;

};

#endif		// #ifndef __CLIENTMANAGER_H__
