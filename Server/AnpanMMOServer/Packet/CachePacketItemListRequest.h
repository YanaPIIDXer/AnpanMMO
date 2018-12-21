/**
 * @file CachePacketItemListRequest.h
 * @brief アイテムリストリクエスト
 * @author NativePacketGenerator
 */

#ifndef __CACHEPACKETITEMLISTREQUEST_H__
#define __CACHEPACKETITEMLISTREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "CacheServerPacketID.h"


/**
 * @brief アイテムリストリクエスト
 */
class CachePacketItemListRequest  : public ProcessPacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @returns パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return CachePacketID::CacheItemListRequest; }

	

	//! キャラクタＩＤ
	u32 CharacterId;
	

	/**
	 * @brief コンストラクタ
	 */
	CachePacketItemListRequest()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	CachePacketItemListRequest(u32 InClientId, u32 InCharacterId)
	{
		ClientId = InClientId;
		CharacterId = InCharacterId;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief シリアライズ
	 * @param[in] pStream ストリーム
	 * @retrns 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		ProcessPacketBase::Serialize(pStream);
		pStream->Serialize(&CharacterId);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETITEMLISTREQUEST_H__
