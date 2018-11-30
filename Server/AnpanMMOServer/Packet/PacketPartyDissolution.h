#ifndef __PACKETPARTYDISSOLUTION_H__
#define __PACKETPARTYDISSOLUTION_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"


class PacketPartyDissolution  : public PacketBase
{
public:
	virtual PacketID GetPacketID() const { return PartyDissolution; }

	

	

	PacketPartyDissolution()
	{
	}

	

	bool Serialize(MemoryStreamInterface *pStream)
	{
		
		return true;
	}
};

#endif		// #ifndef __PACKETPARTYDISSOLUTION_H__
