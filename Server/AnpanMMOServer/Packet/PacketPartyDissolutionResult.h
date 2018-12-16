#ifndef __PACKETPARTYDISSOLUTIONRESULT_H__
#define __PACKETPARTYDISSOLUTIONRESULT_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"


class PacketPartyDissolutionResult  : public PacketBase
{
public:
	virtual u8 GetPacketID() const { return PacketID::PartyDissolutionResult; }

	enum ResultCode
	{
		Success,
		Error,
	};

	u8 Result;
	

	PacketPartyDissolutionResult()
	{
	}

	PacketPartyDissolutionResult(u8 InResult)
	{
		Result = InResult;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Result);
		
		return true;
	}
};

#endif		// #ifndef __PACKETPARTYDISSOLUTIONRESULT_H__
