#ifndef __PACKETTIME_H__
#define __PACKETTIME_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"


class PacketTime  : public PacketBase
{
public:
	virtual PacketID GetPacketID() const { return Time; }

	

	u32 MasterId;
	

	PacketTime()
	{
	}

	PacketTime(u32 InMasterId)
	{
		MasterId = InMasterId;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&MasterId);
		
		return true;
	}
};

#endif		// #ifndef __PACKETTIME_H__
