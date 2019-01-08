/**
 * @file CachePacketItemListResponse.h
 * @brief アイテムリストレスポンスパケット
 * @author NativePacketGenerator
 */

#ifndef __CACHEPACKETITEMLISTRESPONSE_H__
#define __CACHEPACKETITEMLISTRESPONSE_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "ItemData.h"
#include "FlexArray.h"
#include "CacheServerPacketID.h"


/**
 * @brief アイテムリストレスポンスパケット
 */
class CachePacketItemListResponse  : public ProcessPacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return CachePacketID::CacheItemListResponse; }

	enum ResultCode
	{
		//! 成功
		Success,
		//! エラー
		Error,
	};

	//! 結果
	u8 Result;
	//! アイテムリスト
	FlexArray<ItemData> Items;
	

	/**
	 * @brief コンストラクタ
	 */
	CachePacketItemListResponse()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	CachePacketItemListResponse(u32 InClientId, u8 InResult, FlexArray<ItemData> InItems)
	{
		ClientId = InClientId;
		Result = InResult;
		Items = InItems;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief シリアライズ
	 * @param[in] pStream ストリーム
	 * @return 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		ProcessPacketBase::Serialize(pStream);
		pStream->Serialize(&Result);
		Items.Serialize(pStream);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETITEMLISTRESPONSE_H__
