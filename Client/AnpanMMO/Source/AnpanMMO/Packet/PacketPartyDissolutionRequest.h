#ifndef __PACKETPARTYDISSOLUTIONREQUEST_H__
#define __PACKETPARTYDISSOLUTIONREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


class PacketPartyDissolutionRequest  : public PacketBase
{
public:
	virtual u8 GetPacketID() const { return PacketID::PartyDissolutionRequest; }

	

	

	PacketPartyDissolutionRequest()
	{
	}

	

	bool Serialize(MemoryStreamInterface *pStream)
	{
		
		return true;
	}
};

#endif		// #ifndef __PACKETPARTYDISSOLUTIONREQUEST_H__
