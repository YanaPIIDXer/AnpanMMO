#ifndef __CACHEPACKETSAVESKILLLISTRESPONSE_H__
#define __CACHEPACKETSAVESKILLLISTRESPONSE_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"


class CachePacketSaveSkillListResponse  : public ProcessPacketBase
{
public:
	virtual u8 GetPacketID() const { return PacketID::CacheSaveSkillListResponse; }

	enum ResultCode
	{
		Success,
		Error,
	};

	u8 Result;
	u32 SkillId1;
	u32 SkillId2;
	u32 SkillId3;
	u32 SkillId4;
	

	CachePacketSaveSkillListResponse()
	{
	}

	CachePacketSaveSkillListResponse(u32 InClientId, u8 InResult, u32 InSkillId1, u32 InSkillId2, u32 InSkillId3, u32 InSkillId4)
	{
		ClientId = InClientId;
		Result = InResult;
		SkillId1 = InSkillId1;
		SkillId2 = InSkillId2;
		SkillId3 = InSkillId3;
		SkillId4 = InSkillId4;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		ProcessPacketBase::Serialize(pStream);
		pStream->Serialize(&Result);
		pStream->Serialize(&SkillId1);
		pStream->Serialize(&SkillId2);
		pStream->Serialize(&SkillId3);
		pStream->Serialize(&SkillId4);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETSAVESKILLLISTRESPONSE_H__
