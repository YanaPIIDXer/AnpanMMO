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
	

	PacketCreateCharacterRequest()
	{
	}

	PacketCreateCharacterRequest(std::string InCharacterName)
	{
		CharacterName = InCharacterName;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&CharacterName);
		
		return true;
	}
};

#endif		// #ifndef __PACKETCREATECHARACTERREQUEST_H__
