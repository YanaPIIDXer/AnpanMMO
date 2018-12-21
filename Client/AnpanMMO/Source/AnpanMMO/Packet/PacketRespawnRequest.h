#ifndef __PACKETRESPAWNREQUEST_H__
#define __PACKETRESPAWNREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


class PacketRespawnRequest  : public PacketBase
{
public:
	virtual u8 GetPacketID() const { return PacketID::RespawnRequest; }

	

	

	PacketRespawnRequest()
	{
	}

	

	bool Serialize(MemoryStreamInterface *pStream)
	{
		
		return true;
	}
};

#endif		// #ifndef __PACKETRESPAWNREQUEST_H__
