#ifndef __PACKETSKILLTREEOPENRESULT_H__
#define __PACKETSKILLTREEOPENRESULT_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


class PacketSkillTreeOpenResult  : public PacketBase
{
public:
	virtual u8 GetPacketID() const { return PacketID::SkillTreeOpenResult; }

	enum ResultCode
	{
		Success,
		NotEnoughCost,
		NotOpenedParent,
		NotEnoughLevel,
		AlreadyOpened,
		Error,
	};

	u8 Result;
	u32 NodeId;
	

	PacketSkillTreeOpenResult()
	{
	}

	PacketSkillTreeOpenResult(u8 InResult, u32 InNodeId)
	{
		Result = InResult;
		NodeId = InNodeId;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Result);
		pStream->Serialize(&NodeId);
		
		return true;
	}
};

#endif		// #ifndef __PACKETSKILLTREEOPENRESULT_H__
