#include "stdafx.h"
#include "ClientManager.h"

ClientManager ClientManager::Instance;

// コンストラクタ
ClientManager::ClientManager()
	: NextUuid(1)
{
}

// 定期処理.
void ClientManager::Poll()
{
	MapIterator It = Map.begin();
	while (It != Map.end())
	{
		if (!It->second->IsConnected())
		{
			It = Map.erase(It);
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

	u32 Uuid = NextUuid;
	pClient->SetUuid(Uuid);
	NextUuid++;

	// マップに追加。
	Map[Uuid] = pClient;
}

// 取得.
ClientPtr ClientManager::Get(u32 Uuid)
{
	MapIterator It = Map.find(Uuid);
	if (It == Map.end()) { return ClientPtr(); }
	return It->second;
}

// カスタマＩＤから取得.
ClientPtr ClientManager::GetFromCustomerId(u32 CustomerId)
{
	for (MapIterator It = Map.begin(); It != Map.end(); ++It)
	{
		if (It->second->GetCustomerId() == CustomerId) { return It->second; }
	}
	return ClientPtr();
}

// パケットをバラ撒く。
void ClientManager::BroadcastPacket(PacketBase *pPacket)
{
	for (MapIterator It = Map.begin(); It != Map.end(); ++It)
	{
		It->second->SendPacket(pPacket);
	}
}
