#ifndef __CACHEPACKETLOGINREQUEST_H__
#define __CACHEPACKETLOGINREQUEST_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "CachePacketBase.h"


class CachePacketLogInRequest  : public CachePacketBase
{
public:
	virtual PacketID GetPacketID() const { return CacheLogInRequest; }

	

	std::string UserCode;
	

	CachePacketLogInRequest()
	{
	}

	CachePacketLogInRequest(std::string InUserCode)
	{
		UserCode = InUserCode;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		CachePacketBase::Serialize(pStream);
		pStream->Serialize(&UserCode);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETLOGINREQUEST_H__
