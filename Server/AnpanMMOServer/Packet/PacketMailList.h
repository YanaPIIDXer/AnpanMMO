/**
 * @file PacketMailList.h
 * @brief メールリストパケット
 * @author NativePacketGenerator
 */

#ifndef __PACKETMAILLIST_H__
#define __PACKETMAILLIST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "FlexArray.h"
#include "MailData.h"
#include "PacketID.h"


/**
 * @brief メールリストパケット
 */
class PacketMailList  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::MailList; }

	

	//! メールリスト
	FlexArray<MailData> List;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketMailList()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketMailList(FlexArray<MailData> InList)
	{
		List = InList;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief シリアライズ
	 * @param[in] pStream ストリーム
	 * @return 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		List.Serialize(pStream);
		
		return true;
	}
};

#endif		// #ifndef __PACKETMAILLIST_H__
