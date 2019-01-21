/**
 * @file PacketBuyItemRequest.h
 * @brief アイテム購入要求パケット
 * @author NativePacketGenerator
 */

#ifndef __PACKETBUYITEMREQUEST_H__
#define __PACKETBUYITEMREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief アイテム購入要求パケット
 */
class PacketBuyItemRequest  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::BuyItemRequest; }

	

	//! ショップＩＤ
	u32 ShopId;
	//! アイテムＩＤ
	u32 ItemId;
	//! 個数
	u32 Count;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketBuyItemRequest()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketBuyItemRequest(u32 InShopId, u32 InItemId, u32 InCount)
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

#endif		// #ifndef __PACKETBUYITEMREQUEST_H__
