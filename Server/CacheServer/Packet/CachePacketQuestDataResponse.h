#ifndef __CACHEPACKETQUESTDATARESPONSE_H__
#define __CACHEPACKETQUESTDATARESPONSE_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "FlexArray.h"
#include "QuestData.h"


class CachePacketQuestDataResponse  : public ProcessPacketBase
{
public:
	virtual u8 GetPacketID() const { return PacketID::CacheQuestDataResponse; }

	

	FlexArray<QuestData> Quests;
	

	CachePacketQuestDataResponse()
	{
	}

	CachePacketQuestDataResponse(u32 InClientId, FlexArray<QuestData> InQuests)
	{
		ClientId = InClientId;
		Quests = InQuests;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		ProcessPacketBase::Serialize(pStream);
		Quests.Serialize(pStream);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETQUESTDATARESPONSE_H__
