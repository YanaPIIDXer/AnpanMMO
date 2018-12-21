/**
 * @file PacketPing.h
 * @brief Ping
 * @author NativePacketGenerator
 */

#ifndef __PACKETPING_H__
#define __PACKETPING_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief Ping
 */
class PacketPing  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @returns パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::Ping; }

	

	

	/**
	 * @brief コンストラクタ
	 */
	PacketPing()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief シリアライズ
	 * @param in pStream ストリーム
	 * @retrns 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		
		return true;
	}
};

#endif		// #ifndef __PACKETPING_H__
