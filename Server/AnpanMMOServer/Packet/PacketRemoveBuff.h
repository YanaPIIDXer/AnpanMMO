/**
 * @file PacketRemoveBuff.h
 * @brief バフ消失パケット
 * @author NativePacketGenerator
 */

#ifndef __PACKETREMOVEBUFF_H__
#define __PACKETREMOVEBUFF_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief バフ消失パケット
 */
class PacketRemoveBuff  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::RemoveBuff; }

	

	//! バフタイプ
	u8 BuffType;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketRemoveBuff()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketRemoveBuff(u8 InBuffType)
	{
		BuffType = InBuffType;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief シリアライズ
	 * @param[in] pStream ストリーム
	 * @return 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&BuffType);
		
		return true;
	}
};

#endif		// #ifndef __PACKETREMOVEBUFF_H__
