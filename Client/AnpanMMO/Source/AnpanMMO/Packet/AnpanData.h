#ifndef __ANPANDATA_H__
#define __ANPANDATA_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"


class AnpanData 
{
public:
	

	

	u32 Uuid;
	s32 Hp;
	s32 MaxHp;
	

	AnpanData()
	{
	}

	AnpanData(u32 InUuid, s32 InHp, s32 InMaxHp)
	{
		Uuid = InUuid;
		Hp = InHp;
		MaxHp = InMaxHp;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Uuid);
		pStream->Serialize(&Hp);
		pStream->Serialize(&MaxHp);
		
		return true;
	}
};

#endif		// #ifndef __ANPANDATA_H__
