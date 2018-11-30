#ifndef __PACKETPARTYKICKREQUEST_H__
#define __PACKETPARTYKICKREQUEST_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"


class PacketPartyKickRequest  : public PacketBase
{
public:
	virtual PacketID GetPacketID() const { return PartyKickRequest; }

	

	u32 Uuid;
	

	PacketPartyKickRequest()
	{
	}

	PacketPartyKickRequest(u32 InUuid)
	{
		Uuid = InUuid;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Uuid);
		
		return true;
	}
};

#endif		// #ifndef __PACKETPARTYKICKREQUEST_H__
