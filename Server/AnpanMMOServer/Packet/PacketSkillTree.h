#ifndef __PACKETSKILLTREE_H__
#define __PACKETSKILLTREE_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "FlexArray.h"


class PacketSkillTree  : public PacketBase
{
public:
	virtual u8 GetPacketID() const { return SkillTree; }

	

	FlexArray<SkillTreeNode> Nodes;
	

	PacketSkillTree()
	{
	}

	PacketSkillTree(FlexArray<SkillTreeNode> InNodes)
	{
		Nodes = InNodes;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		Nodes.Serialize(pStream);
		
		return true;
	}
};

#endif		// #ifndef __PACKETSKILLTREE_H__
