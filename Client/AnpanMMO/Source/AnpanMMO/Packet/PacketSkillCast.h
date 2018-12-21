#ifndef __PACKETSKILLCAST_H__
#define __PACKETSKILLCAST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


class PacketSkillCast  : public PacketBase
{
public:
	virtual u8 GetPacketID() const { return PacketID::SkillCast; }

	

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
