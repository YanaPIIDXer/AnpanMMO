/**
 * @file PacketSellItemResult.h
 * @brief アイテム売却結果パケット
 * @author NativePacketGenerator
 */

#ifndef __PACKETSELLITEMRESULT_H__
#define __PACKETSELLITEMRESULT_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief アイテム売却結果パケット
 */
class PacketSellItemResult  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::SellItemResult; }

	enum ResultCode
	{
		//! 成功
		Success,
		//! 無効なショップＩＤ
		InvalidShopId,
		//! 無効なアイテム
		InvalidItem,
		//! アイテムを持っていない
		NotHaveItem,
	};

	//! リザルトコード
	u8 Result;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketSellItemResult()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketSellItemResult(u8 InResult)
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

#endif		// #ifndef __PACKETSELLITEMRESULT_H__
