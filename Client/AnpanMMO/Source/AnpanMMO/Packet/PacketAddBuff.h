/**
 * @file PacketAddBuff.h
 * @brief バフ追加パケット
 * @author NativePacketGenerator
 */

#ifndef __PACKETADDBUFF_H__
#define __PACKETADDBUFF_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief バフ追加パケット
 */
class PacketAddBuff  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::AddBuff; }

	

	//! バフＩＤ
	u32 BuffId;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketAddBuff()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketAddBuff(u32 InBuffId)
	{
		BuffId = InBuffId;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief シリアライズ
	 * @param[in] pStream ストリーム
	 * @return 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&BuffId);
		
		return true;
	}
};

#endif		// #ifndef __PACKETADDBUFF_H__
