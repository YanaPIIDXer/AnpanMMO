#ifndef __PACKETPLAYERLIST_H__
#define __PACKETPLAYERLIST_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PlayerData.h"
#include "FlexArray.h"


class PacketPlayerList  : public PacketBase
{
public:
	virtual PacketID GetPacketID() const { return PlayerList; }

	

	FlexArray<PlayerData> List;
	

	PacketPlayerList()
	{
	}

	PacketPlayerList(FlexArray<PlayerData> InList)
	{
		List = InList;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		List.Serialize(pStream);
		
		return true;
	}
};

#endif		// #ifndef __PACKETPLAYERLIST_H__
