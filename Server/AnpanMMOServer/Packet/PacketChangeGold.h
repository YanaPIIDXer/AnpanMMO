/**
 * @file PacketChangeGold.h
 * @brief ゴールド変化
 * @author NativePacketGenerator
 */

#ifndef __PACKETCHANGEGOLD_H__
#define __PACKETCHANGEGOLD_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief ゴールド変化
 */
class PacketChangeGold  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @returns パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::ChangeGold; }

	

	//! 
u32 Gold;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketChangeGold()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketChangeGold(u32 InGold)
	{
		Gold = InGold;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief シリアライズ
	 * @param in pStream ストリーム
	 * @retrns 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Gold);
		
		return true;
	}
};

#endif		// #ifndef __PACKETCHANGEGOLD_H__
