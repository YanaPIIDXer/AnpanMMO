#ifndef __CACHEPACKETOPENSKILLTREE_H__
#define __CACHEPACKETOPENSKILLTREE_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"


class CachePacketOpenSkillTree  : public ProcessPacketBase
{
public:
	virtual u8 GetPacketID() const { return CacheOpenSkillTree; }

	

	u32 CharacterId;
	u32 NodeId;
	

	CachePacketOpenSkillTree()
	{
	}

	CachePacketOpenSkillTree(u32 InClientId, u32 InCharacterId, u32 InNodeId)
	{
		ClientId = InClientId;
		CharacterId = InCharacterId;
		NodeId = InNodeId;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		ProcessPacketBase::Serialize(pStream);
		pStream->Serialize(&CharacterId);
		pStream->Serialize(&NodeId);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETOPENSKILLTREE_H__
