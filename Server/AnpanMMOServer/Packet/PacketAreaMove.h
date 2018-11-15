#ifndef __PACKETAREAMOVE_H__
#define __PACKETAREAMOVE_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"


class PacketAreaMove  : public PacketBase
{
public:
	virtual PacketID GetPacketID() const { return AreaMove; }

	

	u32 AreaId;
	float X;
	float Y;
	

	PacketAreaMove()
	{
	}

	PacketAreaMove(u32 InAreaId, float InX, float InY)
	{
		AreaId = InAreaId;
		X = InX;
		Y = InY;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&AreaId);
		pStream->Serialize(&X);
		pStream->Serialize(&Y);
		
		return true;
	}
};

#endif		// #ifndef __PACKETAREAMOVE_H__
