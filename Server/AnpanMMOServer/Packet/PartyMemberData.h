#ifndef __PARTYMEMBERDATA_H__
#define __PARTYMEMBERDATA_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"


class PartyMemberData 
{
public:
	

	

	u32 Uuid;
	std::string CharacterName;
	

	PartyMemberData()
	{
	}

	PartyMemberData(u32 InUuid, std::string InCharacterName)
	{
		Uuid = InUuid;
		CharacterName = InCharacterName;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Uuid);
		pStream->Serialize(&CharacterName);
		
		return true;
	}
};

#endif		// #ifndef __PARTYMEMBERDATA_H__
