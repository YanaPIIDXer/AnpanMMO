/**
 * @file PacketBuyItemResult.h
 * @brief アイテム購入結果パケット
 * @author NativePacketGenerator
 */

#ifndef __PACKETBUYITEMRESULT_H__
#define __PACKETBUYITEMRESULT_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief アイテム購入結果パケット
 */
class PacketBuyItemResult  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::BuyItemResult; }

	enum ResultCode
	{
		//! 成功
		Success,
		//! 無効なショップＩＤ
		InvalidShopId,
		//! 売られていない
		NotSelling,
		//! 無効なアイテム
		InvalidItem,
		//! ゴールドが足りない
		NotEnougthGold,
	};

	//! リザルトコード
	u8 Result;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketBuyItemResult()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketBuyItemResult(u8 InResult)
	{
		Result = InResult;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief シリアライズ
	 * @param[in] pStream ストリーム
	 * @return 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Result);
		
		return true;
	}
};

#endif		// #ifndef __PACKETBUYITEMRESULT_H__
