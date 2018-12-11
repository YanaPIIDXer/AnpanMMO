#ifndef __PACKETSKILLCAST_H__
#define __PACKETSKILLCAST_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"


class PacketSkillCast  : public PacketBase
{
public:
	virtual PacketID GetPacketID() const { return SkillCast; }

	

	u32 SkillId;
	

	PacketSkillCast()
	{
	}

	PacketSkillCast(u32 InSkillId)
	{
		SkillId = InSkillId;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&SkillId);
		
		return true;
	}
};

#endif		// #ifndef __PACKETSKILLCAST_H__
