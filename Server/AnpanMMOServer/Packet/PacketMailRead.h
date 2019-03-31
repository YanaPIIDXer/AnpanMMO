/**
 * @file PacketMailRead.h
 * @brief メール開封パケット
 * @author NativePacketGenerator
 */

#ifndef __PACKETMAILREAD_H__
#define __PACKETMAILREAD_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief メール開封パケット
 */
class PacketMailRead  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::MailRead; }

	

	//! ＩＤ
	u32 Id;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketMailRead()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketMailRead(u32 InId)
	{
		Id = InId;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief シリアライズ
	 * @param[in] pStream ストリーム
	 * @return 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Id);
		
		return true;
	}
};

#endif		// #ifndef __PACKETMAILREAD_H__
