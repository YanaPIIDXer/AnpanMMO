#ifndef __PACKETROTATEANPAN_H__
#define __PACKETROTATEANPAN_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"


class PacketRotateAnpan  : public PacketBase
{
public:
	virtual u8 GetPacketID() const { return RotateAnpan; }

	

	u32 Uuid;
	float Rotation;
	s32 RotateMilliSec;
	

	PacketRotateAnpan()
	{
	}

	PacketRotateAnpan(u32 InUuid, float InRotation, s32 InRotateMilliSec)
	{
		Uuid = InUuid;
		Rotation = InRotation;
		RotateMilliSec = InRotateMilliSec;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Uuid);
		pStream->Serialize(&Rotation);
		pStream->Serialize(&RotateMilliSec);
		
		return true;
	}
};

#endif		// #ifndef __PACKETROTATEANPAN_H__
