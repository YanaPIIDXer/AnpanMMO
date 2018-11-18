#ifndef __PACKETPLAYERRESPAWN_H__
#define __PACKETPLAYERRESPAWN_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"


class PacketPlayerRespawn  : public PacketBase
{
public:
	virtual PacketID GetPacketID() const { return PlayerRespawn; }

	

	u32 Uuid;
	float X;
	float Y;
	float Z;
	

	PacketPlayerRespawn()
	{
	}

	PacketPlayerRespawn(u32 InUuid, float InX, float InY, float InZ)
	{
		Uuid = InUuid;
		X = InX;
		Y = InY;
		Z = InZ;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Uuid);
		pStream->Serialize(&X);
		pStream->Serialize(&Y);
		pStream->Serialize(&Z);
		
		return true;
	}
};

#endif		// #ifndef __PACKETPLAYERRESPAWN_H__
