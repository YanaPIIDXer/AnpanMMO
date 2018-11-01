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
	typedef std::vector<ClientSharedPtr> ClientList;
	typedef ClientList::iterator ListIterator;

public:

	// デストラクタ
	~ClientManager() {}

	// 定期処理.
	void Poll();

	// クライアント生成.
	void CreateClient(const shared_ptr<tcp::socket> &pSocket);

private:

	// クライアントリスト
	ClientList List;

	// ======== Singleton ============
public:

	static ClientManager &GetInstance() { return Instance; }

private:

	ClientManager();
	static ClientManager Instance;

};

#endif		// #ifndef __CLIENTMANAGER_H__
