#ifndef __PACKETCREATECHARACTERRESULT_H__
#define __PACKETCREATECHARACTERRESULT_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"


class PacketCreateCharacterResult  : public PacketBase
{
public:
	virtual u8 GetPacketID() const { return PacketID::CreateCharacterResult; }

	enum ResultCode
	{
		Success,
		TooLongName,
		EmptyName,
		Error,
	};

	u8 Result;
	

	PacketCreateCharacterResult()
	{
	}

	PacketCreateCharacterResult(u8 InResult)
	{
		Result = InResult;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Result);
		
		return true;
	}
};

#endif		// #ifndef __PACKETCREATECHARACTERRESULT_H__
