#ifndef __PACKETSKILLRECAST_H__
#define __PACKETSKILLRECAST_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"


class PacketSkillRecast  : public PacketBase
{
public:
	virtual u8 GetPacketID() const { return SkillRecast; }

	

	u32 SkillId;
	

	PacketSkillRecast()
	{
	}

	PacketSkillRecast(u32 InSkillId)
	{
		SkillId = InSkillId;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&SkillId);
		
		return true;
	}
};

#endif		// #ifndef __PACKETSKILLRECAST_H__
