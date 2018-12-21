#ifndef __CACHEPACKETSCRIPTFLAGREQUEST_H__
#define __CACHEPACKETSCRIPTFLAGREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "CacheServerPacketID.h"


class CachePacketScriptFlagRequest  : public ProcessPacketBase
{
public:
	virtual u8 GetPacketID() const { return CachePacketID::CacheScriptFlagRequest; }

	

	u32 CharacterId;
	

	CachePacketScriptFlagRequest()
	{
	}

	CachePacketScriptFlagRequest(u32 InClientId, u32 InCharacterId)
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

#endif		// #ifndef __CACHEPACKETSCRIPTFLAGREQUEST_H__
