#ifndef __CACHEPACKETITEMSHORTCUTRESPONSE_H__
#define __CACHEPACKETITEMSHORTCUTRESPONSE_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "CacheServerPacketID.h"


class CachePacketItemShortcutResponse  : public ProcessPacketBase
{
public:
	virtual u8 GetPacketID() const { return CachePacketID::CacheItemShortcutResponse; }

	enum ResultCode
	{
		Success,
		Error,
	};

	u8 Result;
	u32 ItemId1;
	u32 ItemId2;
	

	CachePacketItemShortcutResponse()
	{
	}

	CachePacketItemShortcutResponse(u32 InClientId, u8 InResult, u32 InItemId1, u32 InItemId2)
	{
		ClientId = InClientId;
		Result = InResult;
		ItemId1 = InItemId1;
		ItemId2 = InItemId2;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		ProcessPacketBase::Serialize(pStream);
		pStream->Serialize(&Result);
		pStream->Serialize(&ItemId1);
		pStream->Serialize(&ItemId2);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETITEMSHORTCUTRESPONSE_H__
