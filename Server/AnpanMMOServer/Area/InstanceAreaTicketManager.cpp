#include "stdafx.h"
#include "InstanceAreaTicketManager.h"
#include "InstanceAreaTicket.h"

InstanceAreaTicketManager InstanceAreaTicketManager::Instance;

// コンストラクタ
InstanceAreaTicketManager::InstanceAreaTicketManager()
	: NextUuid(1)
{
}

// デストラクタ
InstanceAreaTicketManager::~InstanceAreaTicketManager()
{
	for (TicketMap::iterator It = TicketList.begin(); It != TicketList.end(); ++It)
	{
		delete It->second;
	}
}

// 発行.
InstanceAreaTicket *InstanceAreaTicketManager::Publish()
{
	InstanceAreaTicket *pTicket = new InstanceAreaTicket();

	u32 Uuid = NextUuid;
	TicketList[Uuid] = pTicket;
	NextUuid++;

	return pTicket;
}

// 取得.
InstanceAreaTicket *InstanceAreaTicketManager::Get(u32 Uuid)
{
	if (TicketList.find(Uuid) == TicketList.end()) { return NULL; }
	return TicketList[Uuid];
}

// 消去.
void InstanceAreaTicketManager::Remove(u32 Uuid)
{
	if (TicketList.find(Uuid) == TicketList.end()) { return; }
	delete TicketList[Uuid];
	TicketList.erase(Uuid);
}
