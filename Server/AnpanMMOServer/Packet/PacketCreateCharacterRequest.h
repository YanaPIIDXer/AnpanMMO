#ifndef __PACKETCREATECHARACTERREQUEST_H__
#define __PACKETCREATECHARACTERREQUEST_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"


class PacketCreateCharacterRequest  : public PacketBase
{
public:
	virtual PacketID GetPacketID() const { return CreateCharacterRequest; }

	

	std::string CharacterName;
	u8 Job;
	

	PacketCreateCharacterRequest()
	{
	}

	PacketCreateCharacterRequest(std::string InCharacterName, u8 InJob)
	{
		CharacterName = InCharacterName;
		Job = InJob;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&CharacterName);
		pStream->Serialize(&Job);
		
		return true;
	}
};

#endif		// #ifndef __PACKETCREATECHARACTERREQUEST_H__
