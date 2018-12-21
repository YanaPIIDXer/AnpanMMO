/**
 * @file CachePacketCharacterDataRequest.h
 * @brief キャラクタ情報リクエスト
 * @author NativePacketGenerator
 */

#ifndef __CACHEPACKETCHARACTERDATAREQUEST_H__
#define __CACHEPACKETCHARACTERDATAREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "CacheServerPacketID.h"


/**
 * @brief キャラクタ情報リクエスト
 */
class CachePacketCharacterDataRequest  : public ProcessPacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @returns パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return CachePacketID::CacheCharacterDataRequest; }

	

	//! 
u32 CustomerId;
	

	/**
	 * @brief コンストラクタ
	 */
	CachePacketCharacterDataRequest()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	CachePacketCharacterDataRequest(u32 InClientId, u32 InCustomerId)
	{
		ClientId = InClientId;
		CustomerId = InCustomerId;
		
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
		pStream->Serialize(&CustomerId);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETCHARACTERDATAREQUEST_H__
