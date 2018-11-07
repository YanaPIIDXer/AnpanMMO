#ifndef __PLAYERDATA_H__
#define __PLAYERDATA_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"


class PlayerData 
{
public:
	

	

	u32 Uuid;
	float X;
	float Y;
	float Rotation;
	

	PlayerData()
	{
	}

	PlayerData(u32 InUuid, float InX, float InY, float InRotation)
	{
		Uuid = InUuid;
		X = InX;
		Y = InY;
		Rotation = InRotation;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Uuid);
		pStream->Serialize(&X);
		pStream->Serialize(&Y);
		pStream->Serialize(&Rotation);
		
		return true;
	}
};

#endif		// #ifndef __PLAYERDATA_H__
