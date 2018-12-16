#ifndef __PACKETAREAMOVE_H__
#define __PACKETAREAMOVE_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"


class PacketAreaMove  : public PacketBase
{
public:
	virtual u8 GetPacketID() const { return PacketID::AreaMove; }

	

	u32 AreaId;
	float X;
	float Y;
	float Z;
	

	PacketAreaMove()
	{
	}

	PacketAreaMove(u32 InAreaId, float InX, float InY, float InZ)
	{
		AreaId = InAreaId;
		X = InX;
		Y = InY;
		Z = InZ;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&AreaId);
		pStream->Serialize(&X);
		pStream->Serialize(&Y);
		pStream->Serialize(&Z);
		
		return true;
	}
};

#endif		// #ifndef __PACKETAREAMOVE_H__
