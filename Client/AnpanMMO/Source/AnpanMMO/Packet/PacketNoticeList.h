#ifndef __PACKETNOTICELIST_H__
#define __PACKETNOTICELIST_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "NoticeData.h"
#include "FlexArray.h"


class PacketNoticeList  : public PacketBase
{
public:
	virtual u8 GetPacketID() const { return NoticeList; }

	

	FlexArray<NoticeData> Notices;
	

	PacketNoticeList()
	{
	}

	PacketNoticeList(FlexArray<NoticeData> InNotices)
	{
		Notices = InNotices;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		Notices.Serialize(pStream);
		
		return true;
	}
};

#endif		// #ifndef __PACKETNOTICELIST_H__
