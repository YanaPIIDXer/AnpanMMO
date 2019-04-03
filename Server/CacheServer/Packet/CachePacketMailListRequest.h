/**
 * @file CachePacketMailListRequest.h
 * @brief メールリストリクエストパケット
 * @author NativePacketGenerator
 */

#ifndef __CACHEPACKETMAILLISTREQUEST_H__
#define __CACHEPACKETMAILLISTREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "CacheServerPacketID.h"


/**
 * @brief メールリストリクエストパケット
 */
class CachePacketMailListRequest  : public ProcessPacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return CachePacketID::CacheMailListRequest; }

	

	//! カスタマＩＤ
	u32 CustomerId;
	

	/**
	 * @brief コンストラクタ
	 */
	CachePacketMailListRequest()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	CachePacketMailListRequest(u32 InClientId, u32 InCustomerId)
	{
		ClientId = InClientId;
		CustomerId = InCustomerId;
		
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
		pStream->Serialize(&CustomerId);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETMAILLISTREQUEST_H__
