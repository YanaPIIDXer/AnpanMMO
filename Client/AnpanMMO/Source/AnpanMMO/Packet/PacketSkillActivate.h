#ifndef __PACKETSKILLACTIVATE_H__
#define __PACKETSKILLACTIVATE_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


class PacketSkillActivate  : public PacketBase
{
public:
	virtual u8 GetPacketID() const { return PacketID::SkillActivate; }

	

	u8 CharacterType;
	u32 CharacterUuid;
	u32 SkillId;
	

	PacketSkillActivate()
	{
	}

	PacketSkillActivate(u8 InCharacterType, u32 InCharacterUuid, u32 InSkillId)
	{
		CharacterType = InCharacterType;
		CharacterUuid = InCharacterUuid;
		SkillId = InSkillId;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&CharacterType);
		pStream->Serialize(&CharacterUuid);
		pStream->Serialize(&SkillId);
		
		return true;
	}
};

#endif		// #ifndef __PACKETSKILLACTIVATE_H__
