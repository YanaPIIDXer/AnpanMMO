/**
 * @file PacketMailListRequest.h
 * @brief メールリスト要求パケット
 * @author NativePacketGenerator
 */

#ifndef __PACKETMAILLISTREQUEST_H__
#define __PACKETMAILLISTREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief メールリスト要求パケット
 */
class PacketMailListRequest  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::MailListRequest; }

	

	

	/**
	 * @brief コンストラクタ
	 */
	PacketMailListRequest()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief シリアライズ
	 * @param[in] pStream ストリーム
	 * @return 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		
		return true;
	}
};

#endif		// #ifndef __PACKETMAILLISTREQUEST_H__
