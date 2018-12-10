#ifndef __PACKETSKILLCASTFINISH_H__
#define __PACKETSKILLCASTFINISH_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"


class PacketSkillCastFinish  : public PacketBase
{
public:
	virtual PacketID GetPacketID() const { return SkillCastFinish; }

	

	

	PacketSkillCastFinish()
	{
	}

	

	bool Serialize(MemoryStreamInterface *pStream)
	{
		
		return true;
	}
};

#endif		// #ifndef __PACKETSKILLCASTFINISH_H__
