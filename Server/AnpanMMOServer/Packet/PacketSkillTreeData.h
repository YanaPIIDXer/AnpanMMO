#ifndef __PACKETSKILLTREEDATA_H__
#define __PACKETSKILLTREEDATA_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "FlexArray.h"
#include "SkillTreeNode.h"


class PacketSkillTreeData  : public PacketBase
{
public:
	virtual u8 GetPacketID() const { return PacketID::SkillTreeData; }

	

	FlexArray<SkillTreeNode> Nodes;
	

	PacketSkillTreeData()
	{
	}

	PacketSkillTreeData(FlexArray<SkillTreeNode> InNodes)
	{
		Nodes = InNodes;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		Nodes.Serialize(pStream);
		
		return true;
	}
};

#endif		// #ifndef __PACKETSKILLTREEDATA_H__
