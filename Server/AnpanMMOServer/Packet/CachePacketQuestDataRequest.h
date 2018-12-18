#ifndef __CACHEPACKETQUESTDATAREQUEST_H__
#define __CACHEPACKETQUESTDATAREQUEST_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"


class CachePacketQuestDataRequest  : public ProcessPacketBase
{
public:
	virtual u8 GetPacketID() const { return PacketID::CacheQuestDataRequest; }

	

	u32 CharacterId;
	

	CachePacketQuestDataRequest()
	{
	}

	CachePacketQuestDataRequest(u32 InClientId, u32 InCharacterId)
	{
		ClientId = InClientId;
		CharacterId = InCharacterId;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		ProcessPacketBase::Serialize(pStream);
		pStream->Serialize(&CharacterId);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETQUESTDATAREQUEST_H__
