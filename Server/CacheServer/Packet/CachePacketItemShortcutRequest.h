#ifndef __CACHEPACKETITEMSHORTCUTREQUEST_H__
#define __CACHEPACKETITEMSHORTCUTREQUEST_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"


class CachePacketItemShortcutRequest  : public ProcessPacketBase
{
public:
	virtual u8 GetPacketID() const { return PacketID::CacheItemShortcutRequest; }

	

	u32 CharacterId;
	

	CachePacketItemShortcutRequest()
	{
	}

	CachePacketItemShortcutRequest(u32 InClientId, u32 InCharacterId)
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

#endif		// #ifndef __CACHEPACKETITEMSHORTCUTREQUEST_H__
