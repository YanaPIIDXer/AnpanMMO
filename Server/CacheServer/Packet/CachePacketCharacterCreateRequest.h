#ifndef __CACHEPACKETCHARACTERCREATEREQUEST_H__
#define __CACHEPACKETCHARACTERCREATEREQUEST_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "StringPack.h"
#include "ProcessPacketBase.h"


class CachePacketCharacterCreateRequest  : public ProcessPacketBase
{
public:
	virtual PacketID GetPacketID() const { return CacheCharacterCreateRequest; }

	

	StringPack<32> CharacterName;
	

	CachePacketCharacterCreateRequest()
	{
	}

	CachePacketCharacterCreateRequest(u32 InClientId, StringPack<32> InCharacterName)
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

#endif		// #ifndef __CACHEPACKETCHARACTERCREATEREQUEST_H__
