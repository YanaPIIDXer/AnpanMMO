#ifndef __CACHEPACKETSAVESKILLLISTRESPONSE_H__
#define __CACHEPACKETSAVESKILLLISTRESPONSE_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"


class CachePacketSaveSkillListResponse  : public ProcessPacketBase
{
public:
	virtual u8 GetPacketID() const { return CacheSaveSkillListResponse; }

	enum ResultCode
	{
		Success,
		Error,
	};

	u8 Result;
	

	CachePacketSaveSkillListResponse()
	{
	}

	CachePacketSaveSkillListResponse(u32 InClientId, u8 InResult)
	{
		ClientId = InClientId;
		Result = InResult;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		ProcessPacketBase::Serialize(pStream);
		pStream->Serialize(&Result);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETSAVESKILLLISTRESPONSE_H__
