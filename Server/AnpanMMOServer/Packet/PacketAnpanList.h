#ifndef __PACKETANPANLIST_H__
#define __PACKETANPANLIST_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "FlexArray.h"
#include "AnpanData.h"


class PacketAnpanList  : public PacketBase
{
public:
	virtual PacketID GetPacketID() const { return AnpanList; }

	

	FlexArray<AnpanData> List;
	

	PacketAnpanList()
	{
	}

	PacketAnpanList(FlexArray<AnpanData> InList)
	{
		List = InList;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		List.Serialize(pStream);
		
		return true;
	}
};

#endif		// #ifndef __PACKETANPANLIST_H__
