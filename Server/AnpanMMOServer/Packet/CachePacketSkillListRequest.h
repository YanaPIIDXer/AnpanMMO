#ifndef __CACHEPACKETSKILLLISTREQUEST_H__
#define __CACHEPACKETSKILLLISTREQUEST_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"


class CachePacketSkillListRequest  : public ProcessPacketBase
{
public:
	virtual u8 GetPacketID() const { return CacheSkillListRequest; }

	

	u32 CharacterId;
	

	CachePacketSkillListRequest()
	{
	}

	CachePacketSkillListRequest(u32 InClientId, u32 InCharacterId)
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

#endif		// #ifndef __CACHEPACKETSKILLLISTREQUEST_H__
