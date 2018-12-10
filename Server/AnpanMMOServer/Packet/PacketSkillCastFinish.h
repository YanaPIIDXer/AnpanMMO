#ifndef __PACKETSKILLCASTFINISH_H__
#define __PACKETSKILLCASTFINISH_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"


class PacketSkillCastFinish  : public PacketBase
{
public:
	virtual PacketID GetPacketID() const { return SkillCastFinish; }

	

	u8 CharacterType;
	u32 CharacterUuid;
	

	PacketSkillCastFinish()
	{
	}

	PacketSkillCastFinish(u8 InCharacterType, u32 InCharacterUuid)
	{
		CharacterType = InCharacterType;
		CharacterUuid = InCharacterUuid;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&CharacterType);
		pStream->Serialize(&CharacterUuid);
		
		return true;
	}
};

#endif		// #ifndef __PACKETSKILLCASTFINISH_H__
