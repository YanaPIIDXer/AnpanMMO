/**
 * @file PacketExitShop.h
 * @brief ショップ終了パケット
 * @author NativePacketGenerator
 */

#ifndef __PACKETEXITSHOP_H__
#define __PACKETEXITSHOP_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief ショップ終了パケット
 */
class PacketExitShop  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::ExitShop; }

	

	

	/**
	 * @brief コンストラクタ
	 */
	PacketExitShop()
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

#endif		// #ifndef __PACKETEXITSHOP_H__
