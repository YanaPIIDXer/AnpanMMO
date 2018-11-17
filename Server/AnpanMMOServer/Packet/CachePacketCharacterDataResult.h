#ifndef __CACHEPACKETCHARACTERDATARESULT_H__
#define __CACHEPACKETCHARACTERDATARESULT_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "CachePacketBase.h"


class CachePacketCharacterDataResult  : public CachePacketBase
{
public:
	virtual PacketID GetPacketID() const { return CacheCharacterDataResult; }

	enum ResultCode
	{
		Success,
		Error,
	};

	u8 Result;
	s32 MaxHp;
	s32 Atk;
	s32 Def;
	s32 Exp;
	

	CachePacketCharacterDataResult()
	{
	}

	CachePacketCharacterDataResult(u32 InClientId, u8 InResult, s32 InMaxHp, s32 InAtk, s32 InDef, s32 InExp)
	{
		ClientId = InClientId;
		Result = InResult;
		MaxHp = InMaxHp;
		Atk = InAtk;
		Def = InDef;
		Exp = InExp;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		CachePacketBase::Serialize(pStream);
		pStream->Serialize(&Result);
		pStream->Serialize(&MaxHp);
		pStream->Serialize(&Atk);
		pStream->Serialize(&Def);
		pStream->Serialize(&Exp);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETCHARACTERDATARESULT_H__
