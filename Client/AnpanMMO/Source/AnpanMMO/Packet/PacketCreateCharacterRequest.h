#ifndef __PACKETCREATECHARACTERREQUEST_H__
#define __PACKETCREATECHARACTERREQUEST_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "StringPack.h"


class PacketCreateCharacterRequest  : public PacketBase
{
public:
	virtual PacketID GetPacketID() const { return CreateCharacterRequest; }

	

	StringPack<32> CharacterName;
	

	PacketCreateCharacterRequest()
	{
	}

	PacketCreateCharacterRequest(StringPack<32> InCharacterName)
	{
		CharacterName = InCharacterName;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		CharacterName.Serialize(pStream);
		
		return true;
	}
};

#endif		// #ifndef __PACKETCREATECHARACTERREQUEST_H__
