#ifndef __CACHEPACKETCHARACTERDATASAVE_H__
#define __CACHEPACKETCHARACTERDATASAVE_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"


class CachePacketCharacterDataSave  : public ProcessPacketBase
{
public:
	virtual PacketID GetPacketID() const { return CacheCharacterDataSave; }

	

	u32 CustomerId;
	s32 MaxHp;
	s32 Atk;
	s32 Def;
	s32 Exp;
	u32 LastAreaId;
	float LastX;
	float LastY;
	float LastZ;
	

	CachePacketCharacterDataSave()
	{
	}

	CachePacketCharacterDataSave(u32 InClientId, u32 InCustomerId, s32 InMaxHp, s32 InAtk, s32 InDef, s32 InExp, u32 InLastAreaId, float InLastX, float InLastY, float InLastZ)
	{
		ClientId = InClientId;
		CustomerId = InCustomerId;
		MaxHp = InMaxHp;
		Atk = InAtk;
		Def = InDef;
		Exp = InExp;
		LastAreaId = InLastAreaId;
		LastX = InLastX;
		LastY = InLastY;
		LastZ = InLastZ;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		ProcessPacketBase::Serialize(pStream);
		pStream->Serialize(&CustomerId);
		pStream->Serialize(&MaxHp);
		pStream->Serialize(&Atk);
		pStream->Serialize(&Def);
		pStream->Serialize(&Exp);
		pStream->Serialize(&LastAreaId);
		pStream->Serialize(&LastX);
		pStream->Serialize(&LastY);
		pStream->Serialize(&LastZ);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETCHARACTERDATASAVE_H__
