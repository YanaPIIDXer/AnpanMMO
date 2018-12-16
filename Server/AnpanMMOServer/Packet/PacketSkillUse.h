#ifndef __PACKETSKILLUSE_H__
#define __PACKETSKILLUSE_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"


class PacketSkillUse  : public PacketBase
{
public:
	virtual u8 GetPacketID() const { return PacketID::SkillUse; }

	

	u32 SkillId;
	u8 TargetType;
	u32 TargetUuid;
	

	PacketSkillUse()
	{
	}

	PacketSkillUse(u32 InSkillId, u8 InTargetType, u32 InTargetUuid)
	{
		SkillId = InSkillId;
		TargetType = InTargetType;
		TargetUuid = InTargetUuid;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&SkillId);
		pStream->Serialize(&TargetType);
		pStream->Serialize(&TargetUuid);
		
		return true;
	}
};

#endif		// #ifndef __PACKETSKILLUSE_H__
