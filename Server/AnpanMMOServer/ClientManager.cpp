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
	ListIterator It = List.begin();
	while (It != List.end())
	{
		if (!It->get()->IsConnected())
		{
			It = List.erase(It);
		}
		else
		{
			++It;
		}
	}
}

// クライアント生成.
void ClientManager::CreateClient(const shared_ptr<tcp::socket> &pSocket)
{
	Client *pNewClient = new Client(pSocket);
	ClientSharedPtr pClient = ClientSharedPtr(pNewClient);

	// リストに追加。
	List.push_back(pClient);
}
