#ifndef __CACHEPACKETSKILLTREEREQUEST_H__
#define __CACHEPACKETSKILLTREEREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "CacheServerPacketID.h"


class CachePacketSkillTreeRequest  : public ProcessPacketBase
{
public:
	virtual u8 GetPacketID() const { return CachePacketID::CacheSkillTreeRequest; }

	

	u32 CharacterId;
	

	CachePacketSkillTreeRequest()
	{
	}

	CachePacketSkillTreeRequest(u32 InClientId, u32 InCharacterId)
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

#endif		// #ifndef __CACHEPACKETSKILLTREEREQUEST_H__
