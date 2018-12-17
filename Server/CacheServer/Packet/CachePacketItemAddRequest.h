#ifndef __CACHEPACKETITEMADDREQUEST_H__
#define __CACHEPACKETITEMADDREQUEST_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"


class CachePacketItemAddRequest  : public ProcessPacketBase
{
public:
	virtual u8 GetPacketID() const { return PacketID::CacheItemAddRequest; }

	

	u32 CharacterId;
	u32 ItemId;
	u32 Count;
	

	CachePacketItemAddRequest()
	{
	}

	CachePacketItemAddRequest(u32 InClientId, u32 InCharacterId, u32 InItemId, u32 InCount)
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

#endif		// #ifndef __CACHEPACKETITEMADDREQUEST_H__
