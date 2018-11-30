#include "stdafx.h"
#include "InstanceAreaTicket.h"
#include "Client.h"

// コンストラクタ
InstanceAreaTicket::InstanceAreaTicket()
{
}

// クライアント追加.
void InstanceAreaTicket::AddClient(ClientPtr pClient)
{
	ClientList[pClient.lock()->GetUuid()] = pClient;
}
