#ifndef __NOTICEDATA_H__
#define __NOTICEDATA_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"


class NoticeData 
{
public:
	

	enum NoticeType
	{
		PartyInvide,
	};

	u8 Type;
	u32 CustomerId;
	

	NoticeData()
	{
	}

	NoticeData(u8 InType, u32 InCustomerId)
	{
		Type = InType;
		CustomerId = InCustomerId;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Type);
		pStream->Serialize(&CustomerId);
		
		return true;
	}
};

#endif		// #ifndef __NOTICEDATA_H__
