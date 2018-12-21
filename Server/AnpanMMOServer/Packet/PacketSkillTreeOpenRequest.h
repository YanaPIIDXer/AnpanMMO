#ifndef __PACKETSKILLTREEOPENREQUEST_H__
#define __PACKETSKILLTREEOPENREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


class PacketSkillTreeOpenRequest  : public PacketBase
{
public:
	virtual u8 GetPacketID() const { return PacketID::SkillTreeOpenRequest; }

	

	u32 NodeId;
	

	PacketSkillTreeOpenRequest()
	{
	}

	PacketSkillTreeOpenRequest(u32 InNodeId)
	{
		NodeId = InNodeId;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&NodeId);
		
		return true;
	}
};

#endif		// #ifndef __PACKETSKILLTREEOPENREQUEST_H__
