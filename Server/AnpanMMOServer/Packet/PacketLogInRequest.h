#ifndef __PACKETLOGINREQUEST_H__
#define __PACKETLOGINREQUEST_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"


class PacketLogInRequest  : public PacketBase
{
public:
	virtual u8 GetPacketID() const { return PacketID::LogInRequest; }

	

	std::string UserCode;
	

	PacketLogInRequest()
	{
	}

	PacketLogInRequest(std::string InUserCode)
	{
		UserCode = InUserCode;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&UserCode);
		
		return true;
	}
};

#endif		// #ifndef __PACKETLOGINREQUEST_H__
