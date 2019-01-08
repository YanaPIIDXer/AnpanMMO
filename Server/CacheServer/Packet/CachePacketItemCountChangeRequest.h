/**
 * @file CachePacketItemCountChangeRequest.h
 * @brief アイテム数変化リクエストパケット
 * @author NativePacketGenerator
 */

#ifndef __CACHEPACKETITEMCOUNTCHANGEREQUEST_H__
#define __CACHEPACKETITEMCOUNTCHANGEREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "CacheServerPacketID.h"


/**
 * @brief アイテム数変化リクエストパケット
 */
class CachePacketItemCountChangeRequest  : public ProcessPacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return CachePacketID::CacheItemCountChangeRequest; }

	

	//! キャラクタＩＤ
	u32 CharacterId;
	//! アイテムＩＤ
	u32 ItemId;
	//! 個数
	u32 Count;
	

	/**
	 * @brief コンストラクタ
	 */
	CachePacketItemCountChangeRequest()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	CachePacketItemCountChangeRequest(u32 InClientId, u32 InCharacterId, u32 InItemId, u32 InCount)
	{
		ClientId = InClientId;
		CharacterId = InCharacterId;
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
		ProcessPacketBase::Serialize(pStream);
		pStream->Serialize(&CharacterId);
		pStream->Serialize(&ItemId);
		pStream->Serialize(&Count);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETITEMCOUNTCHANGEREQUEST_H__
