#include "stdafx.h"
#include "ClientManager.h"

ClientManager ClientManager::Instance;

// コンストラクタ
ClientManager::ClientManager()
{
}

// 定期処理.
void ClientManager::Poll()
{
	for (ListIterator It = List.begin(); It != List.end(); ++It)
	{
		if (!It->get()->IsConnected())
		{
			It = List.erase(It);
		}
	}
}

// クライアント生成.
void ClientManager::CreateClient(const shared_ptr<tcp::socket> &pSocket)
{
	ClientSharedPtr pClient = ClientSharedPtr(new Client(pSocket));

	// リストに追加。
	List.push_back(pClient);
}
