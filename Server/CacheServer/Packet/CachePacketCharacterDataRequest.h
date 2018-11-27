#ifndef __CACHEPACKETCHARACTERDATAREQUEST_H__
#define __CACHEPACKETCHARACTERDATAREQUEST_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"


class CachePacketCharacterDataRequest  : public ProcessPacketBase
{
public:
	virtual PacketID GetPacketID() const { return CacheCharacterDataRequest; }

	

	u32 CustomerId;
	

	CachePacketCharacterDataRequest()
	{
	}

	CachePacketCharacterDataRequest(u32 InClientId, u32 InCustomerId)
	{
		ClientId = InClientId;
		CustomerId = InCustomerId;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		ProcessPacketBase::Serialize(pStream);
		pStream->Serialize(&CustomerId);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETCHARACTERDATAREQUEST_H__
