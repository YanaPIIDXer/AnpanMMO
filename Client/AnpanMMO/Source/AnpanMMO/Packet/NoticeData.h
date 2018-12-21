#ifndef __NOTICEDATA_H__
#define __NOTICEDATA_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


class NoticeData 
{
public:
	

	enum NoticeType
	{
		PartyInvide,
	};

	u8 Type;
	u32 CustomerId;
	std::string CharacterName;
	

	NoticeData()
	{
	}

	NoticeData(u8 InType, u32 InCustomerId, std::string InCharacterName)
	{
		Type = InType;
		CustomerId = InCustomerId;
		CharacterName = InCharacterName;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Type);
		pStream->Serialize(&CustomerId);
		pStream->Serialize(&CharacterName);
		
		return true;
	}
};

#endif		// #ifndef __NOTICEDATA_H__
