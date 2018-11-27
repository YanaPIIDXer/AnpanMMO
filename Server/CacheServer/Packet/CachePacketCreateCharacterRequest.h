#ifndef __CACHEPACKETCREATECHARACTERREQUEST_H__
#define __CACHEPACKETCREATECHARACTERREQUEST_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "StringPack.h"
#include "ProcessPacketBase.h"


class CachePacketCreateCharacterRequest  : public ProcessPacketBase
{
public:
	virtual PacketID GetPacketID() const { return CacheCreateCharacterRequest; }

	

	StringPack<32> CharacterName;
	

	CachePacketCreateCharacterRequest()
	{
	}

	CachePacketCreateCharacterRequest(u32 InClientId, StringPack<32> InCharacterName)
	{
		ClientId = InClientId;
		CharacterName = InCharacterName;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		CharacterName.Serialize(pStream);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETCREATECHARACTERREQUEST_H__
