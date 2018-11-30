#ifndef __PACKETPARTYEXITREQUEST_H__
#define __PACKETPARTYEXITREQUEST_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"


class PacketPartyExitRequest  : public PacketBase
{
public:
	virtual PacketID GetPacketID() const { return PartyExitRequest; }

	

	

	PacketPartyExitRequest()
	{
	}

	

	bool Serialize(MemoryStreamInterface *pStream)
	{
		
		return true;
	}
};

#endif		// #ifndef __PACKETPARTYEXITREQUEST_H__
