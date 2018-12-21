#ifndef __CACHEPACKETQUESTDATARESPONSE_H__
#define __CACHEPACKETQUESTDATARESPONSE_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "FlexArray.h"
#include "QuestData.h"
#include "CacheServerPacketID.h"


class CachePacketQuestDataResponse  : public ProcessPacketBase
{
public:
	virtual u8 GetPacketID() const { return CachePacketID::CacheQuestDataResponse; }

	enum ResultCode
	{
		Success,
		Error,
	};

	u8 Result;
	FlexArray<QuestData> Quests;
	u32 ActiveQuestId;
	

	CachePacketQuestDataResponse()
	{
	}

	CachePacketQuestDataResponse(u32 InClientId, u8 InResult, FlexArray<QuestData> InQuests, u32 InActiveQuestId)
	{
		ClientId = InClientId;
		Result = InResult;
		Quests = InQuests;
		ActiveQuestId = InActiveQuestId;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		ProcessPacketBase::Serialize(pStream);
		pStream->Serialize(&Result);
		Quests.Serialize(pStream);
		pStream->Serialize(&ActiveQuestId);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETQUESTDATARESPONSE_H__
