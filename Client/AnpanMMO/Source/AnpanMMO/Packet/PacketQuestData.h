#ifndef __PACKETQUESTDATA_H__
#define __PACKETQUESTDATA_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "FlexArray.h"
#include "QuestData.h"


class PacketQuestData  : public PacketBase
{
public:
	virtual u8 GetPacketID() const { return PacketID::QuestData; }

	

	FlexArray<QuestData> Quests;
	

	PacketQuestData()
	{
	}

	PacketQuestData(FlexArray<QuestData> InQuests)
	{
		Quests = InQuests;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		Quests.Serialize(pStream);
		
		return true;
	}
};

#endif		// #ifndef __PACKETQUESTDATA_H__
