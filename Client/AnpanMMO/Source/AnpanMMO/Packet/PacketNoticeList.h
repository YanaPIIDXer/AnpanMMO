/**
 * @file PacketNoticeList.h
 * @brief 通知リスト
 * @author NativePacketGenerator
 */

#ifndef __PACKETNOTICELIST_H__
#define __PACKETNOTICELIST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "NoticeData.h"
#include "FlexArray.h"
#include "PacketID.h"


/**
 * @brief 通知リスト
 */
class PacketNoticeList  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::NoticeList; }

	

	//! 通知リスト
	FlexArray<NoticeData> Notices;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketNoticeList()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketNoticeList(FlexArray<NoticeData> InNotices)
	{
		Notices = InNotices;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief シリアライズ
	 * @param[in] pStream ストリーム
	 * @return 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		Notices.Serialize(pStream);
		
		return true;
	}
};

#endif		// #ifndef __PACKETNOTICELIST_H__
