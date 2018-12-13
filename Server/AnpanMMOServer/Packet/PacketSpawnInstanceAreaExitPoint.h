#ifndef __PACKETSPAWNINSTANCEAREAEXITPOINT_H__
#define __PACKETSPAWNINSTANCEAREAEXITPOINT_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"


class PacketSpawnInstanceAreaExitPoint  : public PacketBase
{
public:
	virtual u8 GetPacketID() const { return SpawnInstanceAreaExitPoint; }

	

	u32 WarpPointId;
	

	PacketSpawnInstanceAreaExitPoint()
	{
	}

	PacketSpawnInstanceAreaExitPoint(u32 InWarpPointId)
	{
		WarpPointId = InWarpPointId;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&WarpPointId);
		
		return true;
	}
};

#endif		// #ifndef __PACKETSPAWNINSTANCEAREAEXITPOINT_H__
