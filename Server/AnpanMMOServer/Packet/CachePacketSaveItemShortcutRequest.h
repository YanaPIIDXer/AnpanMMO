#ifndef __CACHEPACKETSAVEITEMSHORTCUTREQUEST_H__
#define __CACHEPACKETSAVEITEMSHORTCUTREQUEST_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"


class CachePacketSaveItemShortcutRequest  : public ProcessPacketBase
{
public:
	virtual u8 GetPacketID() const { return PacketID::CacheSaveItemShortcutRequest; }

	

	u32 CharacterId;
	u32 ItemId1;
	u32 ItemId2;
	

	CachePacketSaveItemShortcutRequest()
	{
	}

	CachePacketSaveItemShortcutRequest(u32 InClientId, u32 InCharacterId, u32 InItemId1, u32 InItemId2)
	{
		ClientId = InClientId;
		CharacterId = InCharacterId;
		ItemId1 = InItemId1;
		ItemId2 = InItemId2;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		ProcessPacketBase::Serialize(pStream);
		pStream->Serialize(&CharacterId);
		pStream->Serialize(&ItemId1);
		pStream->Serialize(&ItemId2);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETSAVEITEMSHORTCUTREQUEST_H__
