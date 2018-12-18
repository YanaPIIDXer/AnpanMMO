#ifndef __CACHEPACKETSAVEITEMSHORTCUTRESPONSE_H__
#define __CACHEPACKETSAVEITEMSHORTCUTRESPONSE_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"


class CachePacketSaveItemShortcutResponse  : public ProcessPacketBase
{
public:
	virtual u8 GetPacketID() const { return PacketID::CacheSaveItemShortcutResponse; }

	enum ResultCode
	{
		Success,
		Error,
	};

	u8 Result;
	

	CachePacketSaveItemShortcutResponse()
	{
	}

	CachePacketSaveItemShortcutResponse(u32 InClientId, u8 InResult)
	{
		ClientId = InClientId;
		Result = InResult;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		ProcessPacketBase::Serialize(pStream);
		pStream->Serialize(&Result);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETSAVEITEMSHORTCUTRESPONSE_H__
