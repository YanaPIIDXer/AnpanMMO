#ifndef __PACKETSKILLTREEOPENRESULT_H__
#define __PACKETSKILLTREEOPENRESULT_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"


class PacketSkillTreeOpenResult  : public PacketBase
{
public:
	virtual u8 GetPacketID() const { return SkillTreeOpenResult; }

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
	

	PacketSkillTreeOpenResult()
	{
	}

	PacketSkillTreeOpenResult(u8 InResult)
	{
		Result = InResult;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Result);
		
		return true;
	}
};

#endif		// #ifndef __PACKETSKILLTREEOPENRESULT_H__
