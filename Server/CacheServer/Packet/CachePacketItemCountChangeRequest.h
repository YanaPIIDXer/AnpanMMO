#ifndef __CACHEPACKETITEMCOUNTCHANGEREQUEST_H__
#define __CACHEPACKETITEMCOUNTCHANGEREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "CacheServerPacketID.h"


class CachePacketItemCountChangeRequest  : public ProcessPacketBase
{
public:
	virtual u8 GetPacketID() const { return CachePacketID::CacheItemCountChangeRequest; }

	

	u32 CharacterId;
	u32 ItemId;
	u32 Count;
	

	CachePacketItemCountChangeRequest()
	{
	}

	CachePacketItemCountChangeRequest(u32 InClientId, u32 InCharacterId, u32 InItemId, u32 InCount)
	{
		ClientId = InClientId;
		CharacterId = InCharacterId;
		ItemId = InItemId;
		Count = InCount;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		ProcessPacketBase::Serialize(pStream);
		pStream->Serialize(&CharacterId);
		pStream->Serialize(&ItemId);
		pStream->Serialize(&Count);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETITEMCOUNTCHANGEREQUEST_H__
