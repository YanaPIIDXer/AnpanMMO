#ifndef __CACHEPACKETSAVEACTIVEQUESTREQUEST_H__
#define __CACHEPACKETSAVEACTIVEQUESTREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "CacheServerPacketID.h"


class CachePacketSaveActiveQuestRequest  : public ProcessPacketBase
{
public:
	virtual u8 GetPacketID() const { return CachePacketID::CacheSaveActiveQuestRequest; }

	

	u32 CharacterId;
	u32 QuestId;
	

	CachePacketSaveActiveQuestRequest()
	{
	}

	CachePacketSaveActiveQuestRequest(u32 InClientId, u32 InCharacterId, u32 InQuestId)
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

#endif		// #ifndef __CACHEPACKETSAVEACTIVEQUESTREQUEST_H__
