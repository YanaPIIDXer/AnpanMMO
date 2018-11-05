#ifndef __ANPANDATA_H__
#define __ANPANDATA_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"


class AnpanData 
{
public:
	

	

	u32 Uuid;
	float X;
	float Y;
	s32 Hp;
	s32 MaxHp;
	

	AnpanData()
	{
	}

	AnpanData(u32 InUuid, float InX, float InY, s32 InHp, s32 InMaxHp)
	{
		Uuid = InUuid;
		X = InX;
		Y = InY;
		Hp = InHp;
		MaxHp = InMaxHp;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Uuid);
		pStream->Serialize(&X);
		pStream->Serialize(&Y);
		pStream->Serialize(&Hp);
		pStream->Serialize(&MaxHp);
		
		return true;
	}
};

#endif		// #ifndef __ANPANDATA_H__
