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
	u8 CharacterType;
	u32 CharacterUuid;
	

	PacketSkillCast()
	{
	}

	PacketSkillCast(u32 InSkillId, u8 InCharacterType, u32 InCharacterUuid)
	{
		SkillId = InSkillId;
		CharacterType = InCharacterType;
		CharacterUuid = InCharacterUuid;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&SkillId);
		pStream->Serialize(&CharacterType);
		pStream->Serialize(&CharacterUuid);
		
		return true;
	}
};

#endif		// #ifndef __PACKETSKILLCAST_H__
