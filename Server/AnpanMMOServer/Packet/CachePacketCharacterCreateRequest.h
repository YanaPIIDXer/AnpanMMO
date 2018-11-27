#ifndef __CACHEPACKETCHARACTERCREATEREQUEST_H__
#define __CACHEPACKETCHARACTERCREATEREQUEST_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"


class CachePacketCharacterCreateRequest  : public ProcessPacketBase
{
public:
	virtual PacketID GetPacketID() const { return CacheCharacterCreateRequest; }

	

	std::string CharacterName;
	

	CachePacketCharacterCreateRequest()
	{
	}

	CachePacketCharacterCreateRequest(u32 InClientId, std::string InCharacterName)
	{
		ClientId = InClientId;
		CharacterName = InCharacterName;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&CharacterName);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETCHARACTERCREATEREQUEST_H__
