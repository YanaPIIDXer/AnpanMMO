#ifndef __PACKETPARTYKICK_H__
#define __PACKETPARTYKICK_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


class PacketPartyKick  : public PacketBase
{
public:
	virtual u8 GetPacketID() const { return PacketID::PartyKick; }

	

	u32 Uuid;
	

	PacketPartyKick()
	{
	}

	PacketPartyKick(u32 InUuid)
	{
		Uuid = InUuid;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Uuid);
		
		return true;
	}
};

#endif		// #ifndef __PACKETPARTYKICK_H__
