#ifndef __PACKETAREAMOVEREQUEST_H__
#define __PACKETAREAMOVEREQUEST_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"


class PacketAreaMoveRequest  : public PacketBase
{
public:
	virtual PacketID GetPacketID() const { return AreaMoveRequest; }

	

	u32 AreaId;
	

	PacketAreaMoveRequest()
	{
	}

	PacketAreaMoveRequest(u32 InAreaId)
	{
		AreaId = InAreaId;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&AreaId);
		
		return true;
	}
};

#endif		// #ifndef __PACKETAREAMOVEREQUEST_H__
