#ifndef __CACHEPACKETQUESTRETIREREQUEST_H__
#define __CACHEPACKETQUESTRETIREREQUEST_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "QuestData.h"


class CachePacketQuestRetireRequest  : public ProcessPacketBase
{
public:
	virtual u8 GetPacketID() const { return PacketID::CacheQuestRetireRequest; }

	

	u32 CharacterId;
	u32 QuestId;
	

	CachePacketQuestRetireRequest()
	{
	}

	CachePacketQuestRetireRequest(u32 InClientId, u32 InCharacterId, u32 InQuestId)
	{
		ClientId = InClientId;
		CharacterId = InCharacterId;
		QuestId = InQuestId;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		ProcessPacketBase::Serialize(pStream);
		pStream->Serialize(&CharacterId);
		pStream->Serialize(&QuestId);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETQUESTRETIREREQUEST_H__
