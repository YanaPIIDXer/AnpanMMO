#ifndef __PACKETRESPAWNREQUEST_H__
#define __PACKETRESPAWNREQUEST_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"


class PacketRespawnRequest  : public PacketBase
{
public:
	virtual PacketID GetPacketID() const { return RespawnRequest; }

	

	

	PacketRespawnRequest()
	{
	}

	

	bool Serialize(MemoryStreamInterface *pStream)
	{
		
		return true;
	}
};

#endif		// #ifndef __PACKETRESPAWNREQUEST_H__
