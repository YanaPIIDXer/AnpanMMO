#ifndef __CACHEPACKETSCRIPTFLAGREQUEST_H__
#define __CACHEPACKETSCRIPTFLAGREQUEST_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"


class CachePacketScriptFlagRequest  : public ProcessPacketBase
{
public:
	virtual PacketID GetPacketID() const { return CacheScriptFlagRequest; }

	

	u32 CustomerId;
	

	CachePacketScriptFlagRequest()
	{
	}

	CachePacketScriptFlagRequest(u32 InClientId, u32 InCustomerId)
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

#endif		// #ifndef __CACHEPACKETSCRIPTFLAGREQUEST_H__
