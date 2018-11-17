#ifndef __CACHEPACKETLOGINRESULT_H__
#define __CACHEPACKETLOGINRESULT_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "CachePacketBase.h"


class CachePacketLogInResult  : public CachePacketBase
{
public:
	virtual PacketID GetPacketID() const { return CacheLogInResult; }

	enum ResultCode
	{
		Success,
		Error,
	};

	u8 Result;
	s32 Uuid;
	

	CachePacketLogInResult()
	{
	}

	CachePacketLogInResult(u8 InResult, s32 InUuid)
	{
		Result = InResult;
		Uuid = InUuid;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		CachePacketBase::Serialize(pStream);
		pStream->Serialize(&Result);
		pStream->Serialize(&Uuid);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETLOGINRESULT_H__
