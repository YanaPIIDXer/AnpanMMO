/**
 * @file PacketItemList.h
 * @brief ログイン時アイテムリスト通知
 * @author NativePacketGenerator
 */

#ifndef __PACKETITEMLIST_H__
#define __PACKETITEMLIST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ItemData.h"
#include "FlexArray.h"
#include "PacketID.h"


/**
 * @brief ログイン時アイテムリスト通知
 */
class PacketItemList  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::ItemList; }

	

	//! アイテムリスト
	FlexArray<ItemData> Items;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketItemList()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketItemList(FlexArray<ItemData> InItems)
	{
		Items = InItems;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief シリアライズ
	 * @param[in] pStream ストリーム
	 * @retrn 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		Items.Serialize(pStream);
		
		return true;
	}
};

#endif		// #ifndef __PACKETITEMLIST_H__
