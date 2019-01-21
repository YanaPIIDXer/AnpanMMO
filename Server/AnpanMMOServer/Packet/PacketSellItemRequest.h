/**
 * @file PacketSellItemRequest.h
 * @brief アイテム売却要求パケット
 * @author NativePacketGenerator
 */

#ifndef __PACKETSELLITEMREQUEST_H__
#define __PACKETSELLITEMREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief アイテム売却要求パケット
 */
class PacketSellItemRequest  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::SellItemRequest; }

	

	//! ショップＩＤ
	u32 ShopId;
	//! アイテムＩＤ
	u32 ItemId;
	//! 個数
	u32 Count;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketSellItemRequest()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketSellItemRequest(u32 InShopId, u32 InItemId, u32 InCount)
	{
		ShopId = InShopId;
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
		pStream->Serialize(&ShopId);
		pStream->Serialize(&ItemId);
		pStream->Serialize(&Count);
		
		return true;
	}
};

#endif		// #ifndef __PACKETSELLITEMREQUEST_H__
