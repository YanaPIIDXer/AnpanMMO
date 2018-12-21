#ifndef __PACKETTIME_H__
#define __PACKETTIME_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


class PacketTime  : public PacketBase
{
public:
	virtual u8 GetPacketID() const { return PacketID::Time; }

	

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
