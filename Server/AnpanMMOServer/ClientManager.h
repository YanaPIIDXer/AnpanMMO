#ifndef __CLIENTMANAGER_H__
#define __CLIENTMANAGER_H__

#include <boost/unordered_map.hpp>
#include "Client.h"
#include "WeakPtrDefine.h"

/**
 * クライアント管理.
 */
class ClientManager : noncopyable
{

private:		// 別名定義.

	typedef shared_ptr<Client> ClientSharedPtr;
	typedef unordered_map<u32, ClientSharedPtr> ClientMap;
	typedef ClientMap::iterator MapIterator;

public:

	// デストラクタ
	~ClientManager() {}

	// 定期処理.
	void Poll();

	// クライアント生成.
	void CreateClient(const shared_ptr<tcp::socket> &pSocket);

	// 取得.
	ClientPtr Get(u32 Uuid);

	// カスタマＩＤから取得.
	ClientPtr GetFromCustomerId(u32 CustomerId);

private:

	// クライアントリスト
	ClientMap Map;

	// 次に割り振るUUID
	u32 NextUuid;

	// ======== Singleton ============
public:

	static ClientManager &GetInstance() { return Instance; }

private:

	ClientManager();
	static ClientManager Instance;

};

#endif		// #ifndef __CLIENTMANAGER_H__
