#ifndef __CACHEPACKETITEMLISTREQUEST_H__
#define __CACHEPACKETITEMLISTREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "CacheServerPacketID.h"


class CachePacketItemListRequest  : public ProcessPacketBase
{
public:
	virtual u8 GetPacketID() const { return CachePacketID::CacheItemListRequest; }

	

	u32 CharacterId;
	

	CachePacketItemListRequest()
	{
	}

	CachePacketItemListRequest(u32 InClientId, u32 InCharacterId)
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

#endif		// #ifndef __CACHEPACKETITEMLISTREQUEST_H__
