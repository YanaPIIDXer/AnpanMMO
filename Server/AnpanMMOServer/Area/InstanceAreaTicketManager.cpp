#include "stdafx.h"
#include "InstanceAreaTicketManager.h"
#include "InstanceAreaTicket.h"
#include "Math/Vector3D.h"

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
InstanceAreaTicket *InstanceAreaTicketManager::Publish(u32 AreaId, const Vector3D &StartPosition)
{
	u32 Uuid = NextUuid;
	InstanceAreaTicket *pTicket = new InstanceAreaTicket(Uuid, AreaId, StartPosition);

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
