/**
 * @file CachePacketItemShortcutResponse.h
 * @brief アイテムショートカットレスポンスパケット
 * @author NativePacketGenerator
 */

#ifndef __CACHEPACKETITEMSHORTCUTRESPONSE_H__
#define __CACHEPACKETITEMSHORTCUTRESPONSE_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "CacheServerPacketID.h"


/**
 * @brief アイテムショートカットレスポンスパケット
 */
class CachePacketItemShortcutResponse  : public ProcessPacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return CachePacketID::CacheItemShortcutResponse; }

	enum ResultCode
	{
		//! 成功
		Success,
		//! エラー
		Error,
	};

	//! 結果
	u8 Result;
	//! アイテムＩＤ１
	u32 ItemId1;
	//! アイテムＩＤ２
	u32 ItemId2;
	

	/**
	 * @brief コンストラクタ
	 */
	CachePacketItemShortcutResponse()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	CachePacketItemShortcutResponse(u32 InClientId, u8 InResult, u32 InItemId1, u32 InItemId2)
	{
		ClientId = InClientId;
		Result = InResult;
		ItemId1 = InItemId1;
		ItemId2 = InItemId2;
		
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
		pStream->Serialize(&ItemId1);
		pStream->Serialize(&ItemId2);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETITEMSHORTCUTRESPONSE_H__
