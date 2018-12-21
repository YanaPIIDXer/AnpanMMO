/**
 * @file PacketItemAdd.h
 * @brief アイテム追加
 * @author NativePacketGenerator
 */

#ifndef __PACKETITEMADD_H__
#define __PACKETITEMADD_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief アイテム追加
 */
class PacketItemAdd  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @returns パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::ItemAdd; }

	

	//! 
u32 ItemId;
	//! 
u32 Count;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketItemAdd()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketItemAdd(u32 InItemId, u32 InCount)
	{
		ItemId = InItemId;
		Count = InCount;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief シリアライズ
	 * @param in pStream ストリーム
	 * @retrns 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&ItemId);
		pStream->Serialize(&Count);
		
		return true;
	}
};

#endif		// #ifndef __PACKETITEMADD_H__
