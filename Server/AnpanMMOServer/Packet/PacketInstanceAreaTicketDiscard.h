#ifndef __PACKETINSTANCEAREATICKETDISCARD_H__
#define __PACKETINSTANCEAREATICKETDISCARD_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"


class PacketInstanceAreaTicketDiscard  : public PacketBase
{
public:
	virtual u8 GetPacketID() const { return InstanceAreaTicketDiscard; }

	

	

	PacketInstanceAreaTicketDiscard()
	{
	}

	

	bool Serialize(MemoryStreamInterface *pStream)
	{
		
		return true;
	}
};

#endif		// #ifndef __PACKETINSTANCEAREATICKETDISCARD_H__
