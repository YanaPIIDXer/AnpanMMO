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

}

// クライアント生成.
ClientPtr ClientManager::CreateClient(const shared_ptr<tcp::socket> &pSocket)
{
	ClientSharedPtr pClient = ClientSharedPtr(new Client(pSocket));

	// リストに追加。
	ClientList.push_back(pClient);

	return pClient;
}
