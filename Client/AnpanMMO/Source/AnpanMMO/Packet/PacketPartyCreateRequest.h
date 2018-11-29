#ifndef __PACKETPARTYCREATEREQUEST_H__
#define __PACKETPARTYCREATEREQUEST_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"


class PacketPartyCreateRequest  : public PacketBase
{
public:
	virtual PacketID GetPacketID() const { return PartyCreateRequest; }

	

	

	PacketPartyCreateRequest()
	{
	}

	

	bool Serialize(MemoryStreamInterface *pStream)
	{
		
		return true;
	}
};

#endif		// #ifndef __PACKETPARTYCREATEREQUEST_H__
