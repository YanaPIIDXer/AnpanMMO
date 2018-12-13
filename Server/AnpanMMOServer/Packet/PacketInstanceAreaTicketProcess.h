#ifndef __PACKETINSTANCEAREATICKETPROCESS_H__
#define __PACKETINSTANCEAREATICKETPROCESS_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"


class PacketInstanceAreaTicketProcess  : public PacketBase
{
public:
	virtual u8 GetPacketID() const { return InstanceAreaTicketProcess; }

	enum ProcessType
	{
		Enter,
		Discard,
	};

	u32 TicketId;
	u8 Process;
	

	PacketInstanceAreaTicketProcess()
	{
	}

	PacketInstanceAreaTicketProcess(u32 InTicketId, u8 InProcess)
	{
		TicketId = InTicketId;
		Process = InProcess;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&TicketId);
		pStream->Serialize(&Process);
		
		return true;
	}
};

#endif		// #ifndef __PACKETINSTANCEAREATICKETPROCESS_H__
