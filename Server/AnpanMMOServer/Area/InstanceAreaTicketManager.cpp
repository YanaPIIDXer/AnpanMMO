#include "stdafx.h"
#include "InstanceAreaTicketManager.h"
#include "InstanceAreaTicket.h"

InstanceAreaTicketManager InstanceAreaTicketManager::Instance;

// �R���X�g���N�^
InstanceAreaTicketManager::InstanceAreaTicketManager()
	: NextUuid(1)
{
}

// �f�X�g���N�^
InstanceAreaTicketManager::~InstanceAreaTicketManager()
{
	for (TicketMap::iterator It = TicketList.begin(); It != TicketList.end(); ++It)
	{
		delete It->second;
	}
}

// ���s.
InstanceAreaTicket *InstanceAreaTicketManager::Publish(u32 AreaId)
{
	u32 Uuid = NextUuid;
	InstanceAreaTicket *pTicket = new InstanceAreaTicket(Uuid, AreaId);

	TicketList[Uuid] = pTicket;
	NextUuid++;

	return pTicket;
}

// �擾.
InstanceAreaTicket *InstanceAreaTicketManager::Get(u32 Uuid)
{
	if (TicketList.find(Uuid) == TicketList.end()) { return NULL; }
	return TicketList[Uuid];
}

// ����.
void InstanceAreaTicketManager::Remove(u32 Uuid)
{
	if (TicketList.find(Uuid) == TicketList.end()) { return; }
	delete TicketList[Uuid];
	TicketList.erase(Uuid);
}
