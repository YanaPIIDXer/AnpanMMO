#ifndef __PACKETAREAMOVEREQUEST_H__
#define __PACKETAREAMOVEREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


class PacketAreaMoveRequest  : public PacketBase
{
public:
	virtual u8 GetPacketID() const { return PacketID::AreaMoveRequest; }

	

	u32 AreaMoveId;
	

	PacketAreaMoveRequest()
	{
	}

	PacketAreaMoveRequest(u32 InAreaMoveId)
	{
		AreaMoveId = InAreaMoveId;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&AreaMoveId);
		
		return true;
	}
};

#endif		// #ifndef __PACKETAREAMOVEREQUEST_H__
