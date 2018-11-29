#ifndef __PACKETPARTYDISSOLUTIONREQUEST_H__
#define __PACKETPARTYDISSOLUTIONREQUEST_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"


class PacketPartyDissolutionRequest  : public PacketBase
{
public:
	virtual PacketID GetPacketID() const { return PartyDissolutionRequest; }

	

	

	PacketPartyDissolutionRequest()
	{
	}

	

	bool Serialize(MemoryStreamInterface *pStream)
	{
		
		return true;
	}
};

#endif		// #ifndef __PACKETPARTYDISSOLUTIONREQUEST_H__
