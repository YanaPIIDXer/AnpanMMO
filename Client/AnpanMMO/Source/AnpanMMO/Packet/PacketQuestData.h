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
	u32 ActiveQuestId;
	

	PacketQuestData()
	{
	}

	PacketQuestData(FlexArray<QuestData> InQuests, u32 InActiveQuestId)
	{
		Quests = InQuests;
		ActiveQuestId = InActiveQuestId;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		Quests.Serialize(pStream);
		pStream->Serialize(&ActiveQuestId);
		
		return true;
	}
};

#endif		// #ifndef __PACKETQUESTDATA_H__
