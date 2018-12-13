#ifndef __PACKETEXITPLAYER_H__
#define __PACKETEXITPLAYER_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"


class PacketExitPlayer  : public PacketBase
{
public:
	virtual u8 GetPacketID() const { return ExitPlayer; }

	

	u32 Uuid;
	

	PacketExitPlayer()
	{
	}

	PacketExitPlayer(u32 InUuid)
	{
		Uuid = InUuid;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Uuid);
		
		return true;
	}
};

#endif		// #ifndef __PACKETEXITPLAYER_H__
