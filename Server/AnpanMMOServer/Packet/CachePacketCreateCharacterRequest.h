#ifndef __CACHEPACKETCREATECHARACTERREQUEST_H__
#define __CACHEPACKETCREATECHARACTERREQUEST_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"


class CachePacketCreateCharacterRequest  : public ProcessPacketBase
{
public:
	virtual PacketID GetPacketID() const { return CacheCreateCharacterRequest; }

	

	u32 CustomerId;
	std::string CharacterName;
	

	CachePacketCreateCharacterRequest()
	{
	}

	CachePacketCreateCharacterRequest(u32 InClientId, u32 InCustomerId, std::string InCharacterName)
	{
		ClientId = InClientId;
		CustomerId = InCustomerId;
		CharacterName = InCharacterName;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		ProcessPacketBase::Serialize(pStream);
		pStream->Serialize(&CustomerId);
		pStream->Serialize(&CharacterName);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETCREATECHARACTERREQUEST_H__
