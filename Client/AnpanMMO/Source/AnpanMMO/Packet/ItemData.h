/**
 * @file ItemData.h
 * @brief アイテムデータパケット
 * @author NativePacketGenerator
 */

#ifndef __ITEMDATA_H__
#define __ITEMDATA_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"


/**
 * @brief アイテムデータパケット
 */
class ItemData 
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	

	

	//! アイテム数
	u32 ItemId;
	//! 個数
	u32 Count;
	

	/**
	 * @brief コンストラクタ
	 */
	ItemData()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	ItemData(u32 InItemId, u32 InCount)
	{
		ItemId = InItemId;
		Count = InCount;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief シリアライズ
	 * @param[in] pStream ストリーム
	 * @return 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&ItemId);
		pStream->Serialize(&Count);
		
		return true;
	}
};

#endif		// #ifndef __ITEMDATA_H__
