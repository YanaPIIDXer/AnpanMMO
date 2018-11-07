#ifndef __PLAYERDATA_H__
#define __PLAYERDATA_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"


class PlayerData 
{
public:
	

	

	u32 Uuid;
	s32 X;
	s32 Y;
	

	PlayerData()
	{
	}

	PlayerData(u32 InUuid, s32 InX, s32 InY)
	{
		Uuid = InUuid;
		X = InX;
		Y = InY;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Uuid);
		pStream->Serialize(&X);
		pStream->Serialize(&Y);
		
		return true;
	}
};

#endif		// #ifndef __PLAYERDATA_H__
