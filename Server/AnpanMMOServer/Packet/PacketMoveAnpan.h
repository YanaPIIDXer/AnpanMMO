#ifndef __PACKETMOVEANPAN_H__
#define __PACKETMOVEANPAN_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"


class PacketMoveAnpan  : public PacketBase
{
public:
	virtual PacketID GetPacketID() const { return MoveAnpan; }

	

	u32 Uuid;
	float X;
	float Y;
	s32 MoveMilliSec;
	

	PacketMoveAnpan()
	{
	}

	PacketMoveAnpan(u32 InUuid, float InX, float InY, s32 InMoveMilliSec)
	{
		Uuid = InUuid;
		X = InX;
		Y = InY;
		MoveMilliSec = InMoveMilliSec;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Uuid);
		pStream->Serialize(&X);
		pStream->Serialize(&Y);
		pStream->Serialize(&MoveMilliSec);
		
		return true;
	}
};

#endif		// #ifndef __PACKETMOVEANPAN_H__
