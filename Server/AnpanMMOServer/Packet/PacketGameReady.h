/**
 * @file PacketGameReady.h
 * @brief 準備完了
 * @author NativePacketGenerator
 */

#ifndef __PACKETGAMEREADY_H__
#define __PACKETGAMEREADY_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief 準備完了
 */
class PacketGameReady  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::GameReady; }

	

	

	/**
	 * @brief コンストラクタ
	 */
	PacketGameReady()
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

#endif		// #ifndef __PACKETGAMEREADY_H__
