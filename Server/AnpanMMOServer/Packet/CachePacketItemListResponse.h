#ifndef __CACHEPACKETITEMLISTRESPONSE_H__
#define __CACHEPACKETITEMLISTRESPONSE_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "ItemData.h"
#include "FlexArray.h"


class CachePacketItemListResponse  : public ProcessPacketBase
{
public:
	virtual u8 GetPacketID() const { return PacketID::CacheItemListResponse; }

	

	FlexArray<ItemData> Items;
	

	CachePacketItemListResponse()
	{
	}

	CachePacketItemListResponse(u32 InClientId, FlexArray<ItemData> InItems)
	{
		ClientId = InClientId;
		Items = InItems;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		ProcessPacketBase::Serialize(pStream);
		Items.Serialize(pStream);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETITEMLISTRESPONSE_H__
