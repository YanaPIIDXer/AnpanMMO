#ifndef __PACKETPARTYCREATEREQUEST_H__
#define __PACKETPARTYCREATEREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


class PacketPartyCreateRequest  : public PacketBase
{
public:
	virtual u8 GetPacketID() const { return PacketID::PartyCreateRequest; }

	

	

	PacketPartyCreateRequest()
	{
	}

	

	bool Serialize(MemoryStreamInterface *pStream)
	{
		
		return true;
	}
};

#endif		// #ifndef __PACKETPARTYCREATEREQUEST_H__
