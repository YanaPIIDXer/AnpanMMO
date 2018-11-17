#ifndef __CACHEPACKETLOGOUTPOINTREQUEST_H__
#define __CACHEPACKETLOGOUTPOINTREQUEST_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "CachePacketBase.h"


class CachePacketLogOutPointRequest  : public CachePacketBase
{
public:
	virtual PacketID GetPacketID() const { return CacheLogOutPointRequest; }

	

	u32 CustomerId;
	

	CachePacketLogOutPointRequest()
	{
	}

	CachePacketLogOutPointRequest(u32 InClientId, u32 InCustomerId)
	{
		ClientId = InClientId;
		CustomerId = InCustomerId;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		CachePacketBase::Serialize(pStream);
		pStream->Serialize(&CustomerId);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETLOGOUTPOINTREQUEST_H__
