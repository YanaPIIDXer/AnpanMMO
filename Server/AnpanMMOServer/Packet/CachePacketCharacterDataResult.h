#ifndef __CACHEPACKETCHARACTERDATARESULT_H__
#define __CACHEPACKETCHARACTERDATARESULT_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"


class CachePacketCharacterDataResult  : public ProcessPacketBase
{
public:
	virtual PacketID GetPacketID() const { return CacheCharacterDataResult; }

	enum ResultCode
	{
		Success,
		Error,
	};

	u8 Result;
	std::string Name;
	u8 Job;
	s32 MaxHp;
	s32 Atk;
	s32 Def;
	s32 Exp;
	u32 LastAreaId;
	float LastX;
	float LastY;
	float LastZ;
	

	CachePacketCharacterDataResult()
	{
	}

	CachePacketCharacterDataResult(u32 InClientId, u8 InResult, std::string InName, u8 InJob, s32 InMaxHp, s32 InAtk, s32 InDef, s32 InExp, u32 InLastAreaId, float InLastX, float InLastY, float InLastZ)
	{
		ClientId = InClientId;
		Result = InResult;
		Name = InName;
		Job = InJob;
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
		pStream->Serialize(&Result);
		pStream->Serialize(&Name);
		pStream->Serialize(&Job);
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

#endif		// #ifndef __CACHEPACKETCHARACTERDATARESULT_H__
