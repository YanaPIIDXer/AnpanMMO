#ifndef __CACHEPACKETLOGINREQUEST_H__
#define __CACHEPACKETLOGINREQUEST_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"


class CachePacketLogInRequest  : public ProcessPacketBase
{
public:
	virtual PacketID GetPacketID() const { return CacheLogInRequest; }

	

	std::string UserCode;
	

	CachePacketLogInRequest()
	{
	}

	CachePacketLogInRequest(u32 InClientId, std::string InUserCode)
	{
		ClientId = InClientId;
		UserCode = InUserCode;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		ProcessPacketBase::Serialize(pStream);
		pStream->Serialize(&UserCode);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETLOGINREQUEST_H__
