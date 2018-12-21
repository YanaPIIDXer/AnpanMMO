#ifndef __PACKETPARTYKICKRESULT_H__
#define __PACKETPARTYKICKRESULT_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


class PacketPartyKickResult  : public PacketBase
{
public:
	virtual u8 GetPacketID() const { return PacketID::PartyKickResult; }

	enum ResultCode
	{
		Success,
		Error,
	};

	u8 Result;
	

	PacketPartyKickResult()
	{
	}

	PacketPartyKickResult(u8 InResult)
	{
		Result = InResult;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Result);
		
		return true;
	}
};

#endif		// #ifndef __PACKETPARTYKICKRESULT_H__
