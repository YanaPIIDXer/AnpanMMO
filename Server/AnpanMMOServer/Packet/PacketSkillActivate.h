#ifndef __PACKETSKILLACTIVATE_H__
#define __PACKETSKILLACTIVATE_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"


class PacketSkillActivate  : public PacketBase
{
public:
	virtual PacketID GetPacketID() const { return SkillActivate; }

	

	u32 SkillId;
	

	PacketSkillActivate()
	{
	}

	PacketSkillActivate(u32 InSkillId)
	{
		SkillId = InSkillId;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&SkillId);
		
		return true;
	}
};

#endif		// #ifndef __PACKETSKILLACTIVATE_H__
