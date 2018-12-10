#ifndef __PACKETSKILLACTIVATE_H__
#define __PACKETSKILLACTIVATE_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"


class PacketSkillActivate  : public PacketBase
{
public:
	virtual PacketID GetPacketID() const { return SkillActivate; }

	

	

	PacketSkillActivate()
	{
	}

	

	bool Serialize(MemoryStreamInterface *pStream)
	{
		
		return true;
	}
};

#endif		// #ifndef __PACKETSKILLACTIVATE_H__
