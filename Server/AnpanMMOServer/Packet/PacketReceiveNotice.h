#ifndef __PACKETRECEIVENOTICE_H__
#define __PACKETRECEIVENOTICE_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "NoticeData.h"


class PacketReceiveNotice  : public PacketBase
{
public:
	virtual PacketID GetPacketID() const { return ReceiveNotice; }

	

	NoticeData Notice;
	

	PacketReceiveNotice()
	{
	}

	PacketReceiveNotice(NoticeData InNotice)
	{
		Notice = InNotice;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		Notice.Serialize(pStream);
		
		return true;
	}
};

#endif		// #ifndef __PACKETRECEIVENOTICE_H__
