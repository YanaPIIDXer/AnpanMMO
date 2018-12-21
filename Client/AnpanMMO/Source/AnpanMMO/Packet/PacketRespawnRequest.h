/**
 * @file PacketRespawnRequest.h
 * @brief プレイヤーリスポン要求
 * @author NativePacketGenerator
 */

#ifndef __PACKETRESPAWNREQUEST_H__
#define __PACKETRESPAWNREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief プレイヤーリスポン要求
 */
class PacketRespawnRequest  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @returns パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::RespawnRequest; }

	

	

	/**
	 * @brief コンストラクタ
	 */
	PacketRespawnRequest()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief シリアライズ
	 * @param[in] pStream ストリーム
	 * @retrns 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		
		return true;
	}
};

#endif		// #ifndef __PACKETRESPAWNREQUEST_H__
