#ifndef __PACKETSTOPANPAN_H__
#define __PACKETSTOPANPAN_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"


class PacketStopAnpan  : public PacketBase
{
public:
	virtual PacketID GetPacketID() const { return StopAnpan; }

	

	u32 Uuid;
	float X;
	float Y;
	float Rotation;
	

	PacketStopAnpan()
	{
	}

	PacketStopAnpan(u32 InUuid, float InX, float InY, float InRotation)
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

#endif		// #ifndef __PACKETSTOPANPAN_H__
