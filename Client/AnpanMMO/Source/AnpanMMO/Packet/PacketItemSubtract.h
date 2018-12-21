/**
 * @file PacketItemSubtract.h
 * @brief アイテム消費
 * @author NativePacketGenerator
 */

#ifndef __PACKETITEMSUBTRACT_H__
#define __PACKETITEMSUBTRACT_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief アイテム消費
 */
class PacketItemSubtract  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::ItemSubtract; }

	

	//! アイテムＩＤ
	u32 ItemId;
	//! 個数
	u32 Count;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketItemSubtract()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketItemSubtract(u32 InItemId, u32 InCount)
	{
		ItemId = InItemId;
		Count = InCount;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief シリアライズ
	 * @param[in] pStream ストリーム
	 * @retrn 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&ItemId);
		pStream->Serialize(&Count);
		
		return true;
	}
};

#endif		// #ifndef __PACKETITEMSUBTRACT_H__
