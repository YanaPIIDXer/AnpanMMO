#ifndef __CLIENTMANAGER_H__
#define __CLIENTMANAGER_H__

#include <vector>
#include "Client.h"

typedef weak_ptr<Client> ClientPtr;

/**
 * クライアント管理.
 */
class ClientManager
{

private:		// 別名定義.

	typedef shared_ptr<Client> ClientSharedPtr;

public:

	// コンストラクタ
	ClientManager();

	// デストラクタ
	~ClientManager() {}

private:

	// クライアントリスト
	std::vector<ClientSharedPtr> ClientList;

};

#endif		// #ifndef __CLIENTMANAGER_H__
