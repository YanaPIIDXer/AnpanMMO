#ifndef __PACKETSPAWNINSTANCEAREAEXITPOINT_H__
#define __PACKETSPAWNINSTANCEAREAEXITPOINT_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"


class PacketSpawnInstanceAreaExitPoint  : public PacketBase
{
public:
	virtual PacketID GetPacketID() const { return SpawnInstanceAreaExitPoint; }

	

	u32 WarpDataId;
	

	PacketSpawnInstanceAreaExitPoint()
	{
	}

	PacketSpawnInstanceAreaExitPoint(u32 InWarpDataId)
	{
		WarpDataId = InWarpDataId;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&WarpDataId);
		
		return true;
	}
};

#endif		// #ifndef __PACKETSPAWNINSTANCEAREAEXITPOINT_H__
