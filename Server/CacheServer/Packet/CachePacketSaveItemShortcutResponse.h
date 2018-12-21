#ifndef __CACHEPACKETSAVEITEMSHORTCUTRESPONSE_H__
#define __CACHEPACKETSAVEITEMSHORTCUTRESPONSE_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "CacheServerPacketID.h"


class CachePacketSaveItemShortcutResponse  : public ProcessPacketBase
{
public:
	virtual u8 GetPacketID() const { return CachePacketID::CacheSaveItemShortcutResponse; }

	enum ResultCode
	{
		Success,
		Error,
	};

	u8 Result;
	u32 ItemId1;
	u32 ItemId2;
	

	CachePacketSaveItemShortcutResponse()
	{
	}

	CachePacketSaveItemShortcutResponse(u32 InClientId, u8 InResult, u32 InItemId1, u32 InItemId2)
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

#endif		// #ifndef __CACHEPACKETSAVEITEMSHORTCUTRESPONSE_H__
