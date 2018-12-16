#ifndef __PACKETINSTANCEAREATICKETPUBLISH_H__
#define __PACKETINSTANCEAREATICKETPUBLISH_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"


class PacketInstanceAreaTicketPublish  : public PacketBase
{
public:
	virtual u8 GetPacketID() const { return PacketID::InstanceAreaTicketPublish; }

	

	u32 AreaId;
	u32 TicketId;
	

	PacketInstanceAreaTicketPublish()
	{
	}

	PacketInstanceAreaTicketPublish(u32 InAreaId, u32 InTicketId)
	{
		AreaId = InAreaId;
		TicketId = InTicketId;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&AreaId);
		pStream->Serialize(&TicketId);
		
		return true;
	}
};

#endif		// #ifndef __PACKETINSTANCEAREATICKETPUBLISH_H__
