#ifndef __PACKETINSTANCEAREATICKETDISCARD_H__
#define __PACKETINSTANCEAREATICKETDISCARD_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


class PacketInstanceAreaTicketDiscard  : public PacketBase
{
public:
	virtual u8 GetPacketID() const { return PacketID::InstanceAreaTicketDiscard; }

	

	

	PacketInstanceAreaTicketDiscard()
	{
	}

	

	bool Serialize(MemoryStreamInterface *pStream)
	{
		
		return true;
	}
};

#endif		// #ifndef __PACKETINSTANCEAREATICKETDISCARD_H__
