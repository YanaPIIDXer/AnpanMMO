#ifndef __PACKETPARTYEXIT_H__
#define __PACKETPARTYEXIT_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


class PacketPartyExit  : public PacketBase
{
public:
	virtual u8 GetPacketID() const { return PacketID::PartyExit; }

	

	u32 Uuid;
	

	PacketPartyExit()
	{
	}

	PacketPartyExit(u32 InUuid)
	{
		Uuid = InUuid;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Uuid);
		
		return true;
	}
};

#endif		// #ifndef __PACKETPARTYEXIT_H__
