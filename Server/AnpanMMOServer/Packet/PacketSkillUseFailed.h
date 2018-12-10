#ifndef __PACKETSKILLUSEFAILED_H__
#define __PACKETSKILLUSEFAILED_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"


class PacketSkillUseFailed  : public PacketBase
{
public:
	virtual PacketID GetPacketID() const { return SkillUseFailed; }

	enum ReasonType
	{
		RecastTime,
		Cancel,
	};

	u8 Reason;
	

	PacketSkillUseFailed()
	{
	}

	PacketSkillUseFailed(u8 InReason)
	{
		Reason = InReason;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Reason);
		
		return true;
	}
};

#endif		// #ifndef __PACKETSKILLUSEFAILED_H__
