#ifndef __CACHEPACKETGOLDSAVE_H__
#define __CACHEPACKETGOLDSAVE_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"


class CachePacketGoldSave  : public ProcessPacketBase
{
public:
	virtual PacketID GetPacketID() const { return CacheGoldSave; }

	

	u32 CharacterId;
	u32 Gold;
	

	CachePacketGoldSave()
	{
	}

	CachePacketGoldSave(u32 InClientId, u32 InCharacterId, u32 InGold)
	{
		ClientId = InClientId;
		CharacterId = InCharacterId;
		Gold = InGold;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		ProcessPacketBase::Serialize(pStream);
		pStream->Serialize(&CharacterId);
		pStream->Serialize(&Gold);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETGOLDSAVE_H__
