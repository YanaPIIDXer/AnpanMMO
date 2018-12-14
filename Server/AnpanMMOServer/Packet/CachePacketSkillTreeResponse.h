#ifndef __CACHEPACKETSKILLTREERESPONSE_H__
#define __CACHEPACKETSKILLTREERESPONSE_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"


class CachePacketSkillTreeResponse  : public ProcessPacketBase
{
public:
	virtual u8 GetPacketID() const { return CacheSkillTreeResponse; }

	enum ResultCode
	{
		Success,
		Error,
	};

	u8 Result;
	FlexArray<u32> OpenedList;
	

	CachePacketSkillTreeResponse()
	{
	}

	CachePacketSkillTreeResponse(u32 InClientId, u8 InResult, FlexArray<u32> InOpenedList)
	{
		ClientId = InClientId;
		Result = InResult;
		OpenedList = InOpenedList;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		ProcessPacketBase::Serialize(pStream);
		pStream->Serialize(&Result);
		OpenedList.Serialize(pStream);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETSKILLTREERESPONSE_H__
