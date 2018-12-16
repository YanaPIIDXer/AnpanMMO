#ifndef __PACKETMOVEPLAYER_H__
#define __PACKETMOVEPLAYER_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"


class PacketMovePlayer  : public PacketBase
{
public:
	virtual u8 GetPacketID() const { return PacketID::MovePlayer; }

	

	u32 Uuid;
	float X;
	float Y;
	float Z;
	float Rotation;
	

	PacketMovePlayer()
	{
	}

	PacketMovePlayer(u32 InUuid, float InX, float InY, float InZ, float InRotation)
	{
		Uuid = InUuid;
		X = InX;
		Y = InY;
		Z = InZ;
		Rotation = InRotation;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Uuid);
		pStream->Serialize(&X);
		pStream->Serialize(&Y);
		pStream->Serialize(&Z);
		pStream->Serialize(&Rotation);
		
		return true;
	}
};

#endif		// #ifndef __PACKETMOVEPLAYER_H__
