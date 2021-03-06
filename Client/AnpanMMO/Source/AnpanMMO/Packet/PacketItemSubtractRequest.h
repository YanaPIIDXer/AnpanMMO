/**
 * @file PacketItemSubtractRequest.h
 * @brief アイテム破棄リクエストパケット
 * @author NativePacketGenerator
 */

#ifndef __PACKETITEMSUBTRACTREQUEST_H__
#define __PACKETITEMSUBTRACTREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief アイテム破棄リクエストパケット
 */
class PacketItemSubtractRequest  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::ItemSubtractRequest; }

	

	//! アイテムＩＤ
	u32 ItemId;
	//! 個数
	u32 Count;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketItemSubtractRequest()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketItemSubtractRequest(u32 InItemId, u32 InCount)
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

#endif		// #ifndef __PACKETITEMSUBTRACTREQUEST_H__
