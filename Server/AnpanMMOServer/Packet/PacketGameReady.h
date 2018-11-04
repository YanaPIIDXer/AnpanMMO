#ifndef __PACKETGAMEREADY_H__
#define __PACKETGAMEREADY_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"


class PacketGameReady  : public PacketBase
{
public:
	virtual PacketID GetPacketID() const { return GameReady; }

	

	

	PacketGameReady()
	{
	}

	

	bool Serialize(MemoryStreamInterface *pStream)
	{
		
		return true;
	}
};

#endif		// #ifndef __PACKETGAMEREADY_H__
