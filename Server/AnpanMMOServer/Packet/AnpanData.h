#ifndef __ANPANDATA_H__
#define __ANPANDATA_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


class AnpanData 
{
public:
	

	

	u32 Uuid;
	u32 MasterId;
	float X;
	float Y;
	float Z;
	float Rotation;
	s32 Hp;
	s32 MaxHp;
	

	AnpanData()
	{
	}

	AnpanData(u32 InUuid, u32 InMasterId, float InX, float InY, float InZ, float InRotation, s32 InHp, s32 InMaxHp)
	{
		Uuid = InUuid;
		MasterId = InMasterId;
		X = InX;
		Y = InY;
		Z = InZ;
		Rotation = InRotation;
		Hp = InHp;
		MaxHp = InMaxHp;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Uuid);
		pStream->Serialize(&MasterId);
		pStream->Serialize(&X);
		pStream->Serialize(&Y);
		pStream->Serialize(&Z);
		pStream->Serialize(&Rotation);
		pStream->Serialize(&Hp);
		pStream->Serialize(&MaxHp);
		
		return true;
	}
};

#endif		// #ifndef __ANPANDATA_H__
