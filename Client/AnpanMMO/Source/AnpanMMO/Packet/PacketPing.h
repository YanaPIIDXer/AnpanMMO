#ifndef __PACKETPING_H__
#define __PACKETPING_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"


class PacketPing  : public PacketBase
{
public:
	virtual u8 GetPacketID() const { return PacketID::Ping; }

	

	

	PacketPing()
	{
	}

	

	bool Serialize(MemoryStreamInterface *pStream)
	{
		
		return true;
	}
};

#endif		// #ifndef __PACKETPING_H__
