#ifndef __PACKETNOTICELIST_H__
#define __PACKETNOTICELIST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "NoticeData.h"
#include "FlexArray.h"
#include "PacketID.h"


class PacketNoticeList  : public PacketBase
{
public:
	virtual u8 GetPacketID() const { return PacketID::NoticeList; }

	

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
