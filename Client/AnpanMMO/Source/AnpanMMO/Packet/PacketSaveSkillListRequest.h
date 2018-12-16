#ifndef __PACKETSAVESKILLLISTREQUEST_H__
#define __PACKETSAVESKILLLISTREQUEST_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"


class PacketSaveSkillListRequest  : public PacketBase
{
public:
	virtual u8 GetPacketID() const { return SaveSkillListRequest; }

	

	u32 NodeId1;
	u32 NodeId2;
	u32 NodeId3;
	u32 NodeId4;
	

	PacketSaveSkillListRequest()
	{
	}

	PacketSaveSkillListRequest(u32 InNodeId1, u32 InNodeId2, u32 InNodeId3, u32 InNodeId4)
	{
		NodeId1 = InNodeId1;
		NodeId2 = InNodeId2;
		NodeId3 = InNodeId3;
		NodeId4 = InNodeId4;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&NodeId1);
		pStream->Serialize(&NodeId2);
		pStream->Serialize(&NodeId3);
		pStream->Serialize(&NodeId4);
		
		return true;
	}
};

#endif		// #ifndef __PACKETSAVESKILLLISTREQUEST_H__
