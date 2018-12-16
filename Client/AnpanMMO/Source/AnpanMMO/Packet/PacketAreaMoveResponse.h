#ifndef __PACKETAREAMOVERESPONSE_H__
#define __PACKETAREAMOVERESPONSE_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"


class PacketAreaMoveResponse  : public PacketBase
{
public:
	virtual u8 GetPacketID() const { return PacketID::AreaMoveResponse; }

	enum ResultCode
	{
		Success,
		Fatal,
	};

	u8 Result;
	

	PacketAreaMoveResponse()
	{
	}

	PacketAreaMoveResponse(u8 InResult)
	{
		Result = InResult;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Result);
		
		return true;
	}
};

#endif		// #ifndef __PACKETAREAMOVERESPONSE_H__
