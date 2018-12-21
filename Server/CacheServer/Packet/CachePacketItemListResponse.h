#ifndef __CACHEPACKETITEMLISTRESPONSE_H__
#define __CACHEPACKETITEMLISTRESPONSE_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "ItemData.h"
#include "FlexArray.h"
#include "CacheServerPacketID.h"


class CachePacketItemListResponse  : public ProcessPacketBase
{
public:
	virtual u8 GetPacketID() const { return CachePacketID::CacheItemListResponse; }

	enum ResultCode
	{
		Success,
		Error,
	};

	u8 Result;
	FlexArray<ItemData> Items;
	

	CachePacketItemListResponse()
	{
	}

	CachePacketItemListResponse(u32 InClientId, u8 InResult, FlexArray<ItemData> InItems)
	{
		ClientId = InClientId;
		Result = InResult;
		Items = InItems;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		ProcessPacketBase::Serialize(pStream);
		pStream->Serialize(&Result);
		Items.Serialize(pStream);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETITEMLISTRESPONSE_H__
