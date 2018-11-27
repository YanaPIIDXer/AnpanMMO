#ifndef __CACHEPACKETLOGINRESULT_H__
#define __CACHEPACKETLOGINRESULT_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"


class CachePacketLogInResult  : public ProcessPacketBase
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
	u32 LastAreaId;
	

	CachePacketLogInResult()
	{
	}

	CachePacketLogInResult(u32 InClientId, u8 InResult, s32 InUuid, u32 InLastAreaId)
	{
		ClientId = InClientId;
		Result = InResult;
		Uuid = InUuid;
		LastAreaId = InLastAreaId;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Result);
		pStream->Serialize(&Uuid);
		pStream->Serialize(&LastAreaId);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETLOGINRESULT_H__
