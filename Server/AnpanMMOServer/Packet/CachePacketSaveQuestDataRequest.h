#ifndef __CACHEPACKETSAVEQUESTDATAREQUEST_H__
#define __CACHEPACKETSAVEQUESTDATAREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "QuestData.h"
#include "CacheServerPacketID.h"


class CachePacketSaveQuestDataRequest  : public ProcessPacketBase
{
public:
	virtual u8 GetPacketID() const { return CachePacketID::CacheSaveQuestDataRequest; }

	

	u32 CharacterId;
	QuestData Data;
	

	CachePacketSaveQuestDataRequest()
	{
	}

	CachePacketSaveQuestDataRequest(u32 InClientId, u32 InCharacterId, QuestData InData)
	{
		ClientId = InClientId;
		CharacterId = InCharacterId;
		Data = InData;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		ProcessPacketBase::Serialize(pStream);
		pStream->Serialize(&CharacterId);
		Data.Serialize(pStream);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETSAVEQUESTDATAREQUEST_H__
