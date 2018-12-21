/**
 * @file CachePacketSaveItemShortcutResponse.h
 * @brief アイテムショートカット保存レスポンス
 * @author NativePacketGenerator
 */

#ifndef __CACHEPACKETSAVEITEMSHORTCUTRESPONSE_H__
#define __CACHEPACKETSAVEITEMSHORTCUTRESPONSE_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "CacheServerPacketID.h"


/**
 * @brief アイテムショートカット保存レスポンス
 */
class CachePacketSaveItemShortcutResponse  : public ProcessPacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @returns パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return CachePacketID::CacheSaveItemShortcutResponse; }

	enum ResultCode
	{
		//! 
		Success = 成功,
		//! 
		Error = エラー,
	};

	//! 
u8 Result;
	//! 
u32 ItemId1;
	//! 
u32 ItemId2;
	

	/**
	 * @brief コンストラクタ
	 */
	CachePacketSaveItemShortcutResponse()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	CachePacketSaveItemShortcutResponse(u32 InClientId, u8 InResult, u32 InItemId1, u32 InItemId2)
	{
		ClientId = InClientId;
		Result = InResult;
		ItemId1 = InItemId1;
		ItemId2 = InItemId2;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief シリアライズ
	 * @param in pStream ストリーム
	 * @retrns 成功したらtrueを返す。
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

#endif		// #ifndef __CACHEPACKETSAVEITEMSHORTCUTRESPONSE_H__
