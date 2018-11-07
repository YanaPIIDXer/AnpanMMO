#ifndef __PACKETSPAWNPLAYER_H__
#define __PACKETSPAWNPLAYER_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"


class PacketSpawnPlayer  : public PacketBase
{
public:
	virtual PacketID GetPacketID() const { return SpawnPlayer; }

	

	u32 Uuid;
	

	PacketSpawnPlayer()
	{
	}

	PacketSpawnPlayer(u32 InUuid)
	{
		Uuid = InUuid;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Uuid);
		
		return true;
	}
};

#endif		// #ifndef __PACKETSPAWNPLAYER_H__
