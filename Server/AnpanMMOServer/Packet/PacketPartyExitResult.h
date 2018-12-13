#ifndef __PACKETPARTYEXITRESULT_H__
#define __PACKETPARTYEXITRESULT_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"


class PacketPartyExitResult  : public PacketBase
{
public:
	virtual u8 GetPacketID() const { return PartyExitResult; }

	enum ResultCode
	{
		Success,
		Error,
	};

	u8 Result;
	

	PacketPartyExitResult()
	{
	}

	PacketPartyExitResult(u8 InResult)
	{
		Result = InResult;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Result);
		
		return true;
	}
};

#endif		// #ifndef __PACKETPARTYEXITRESULT_H__
