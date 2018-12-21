#ifndef __SKILLTREENODE_H__
#define __SKILLTREENODE_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


class SkillTreeNode 
{
public:
	

	enum NodeState
	{
		Closed,
		Open,
	};

	u32 NodeId;
	u8 State;
	

	SkillTreeNode()
	{
	}

	SkillTreeNode(u32 InNodeId, u8 InState)
	{
		NodeId = InNodeId;
		State = InState;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&NodeId);
		pStream->Serialize(&State);
		
		return true;
	}
};

#endif		// #ifndef __SKILLTREENODE_H__
