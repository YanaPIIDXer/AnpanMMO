#ifndef __PACKETLOGINRESULT_H__
#define __PACKETLOGINRESULT_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"


class PacketLogInResult  : public PacketBase
{
public:
	virtual PacketID GetPacketID() const { return LogInResult; }

	enum ResultCode
	{
		Success,
		DoubleLogIn,
		Error,
	};

	u8 Result;
	s32 Uuid;
	

	PacketLogInResult()
	{
	}

	PacketLogInResult(u8 InResult, s32 InUuid)
	{
		Result = InResult;
		Uuid = InUuid;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Result);
		pStream->Serialize(&Uuid);
		
		return true;
	}
};

#endif		// #ifndef __PACKETLOGINRESULT_H__
