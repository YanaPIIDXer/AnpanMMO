#ifndef __PACKETPARTYDISSOLUTION_H__
#define __PACKETPARTYDISSOLUTION_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


class PacketPartyDissolution  : public PacketBase
{
public:
	virtual u8 GetPacketID() const { return PacketID::PartyDissolution; }

	

	

	PacketPartyDissolution()
	{
	}

	

	bool Serialize(MemoryStreamInterface *pStream)
	{
		
		return true;
	}
};

#endif		// #ifndef __PACKETPARTYDISSOLUTION_H__
