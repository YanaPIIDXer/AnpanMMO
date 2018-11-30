#ifndef __PACKETINSTANCEAREATICKETPROCESS_H__
#define __PACKETINSTANCEAREATICKETPROCESS_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"


class PacketInstanceAreaTicketProcess  : public PacketBase
{
public:
	virtual PacketID GetPacketID() const { return InstanceAreaTicketProcess; }

	enum ProcessType
	{
		Enter,
		Discard,
	};

	u32 Uuid;
	u8 Process;
	

	PacketInstanceAreaTicketProcess()
	{
	}

	PacketInstanceAreaTicketProcess(u32 InUuid, u8 InProcess)
	{
		Uuid = InUuid;
		Process = InProcess;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Uuid);
		pStream->Serialize(&Process);
		
		return true;
	}
};

#endif		// #ifndef __PACKETINSTANCEAREATICKETPROCESS_H__
