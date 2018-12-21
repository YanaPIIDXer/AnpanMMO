/**
 * @file CachePacketQuestDataRequest.h
 * @brief クエストデータリクエスト
 * @author NativePacketGenerator
 */

#ifndef __CACHEPACKETQUESTDATAREQUEST_H__
#define __CACHEPACKETQUESTDATAREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "CacheServerPacketID.h"


/**
 * @brief クエストデータリクエスト
 */
class CachePacketQuestDataRequest  : public ProcessPacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @returns パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return CachePacketID::CacheQuestDataRequest; }

	

	//! 
u32 CharacterId;
	

	/**
	 * @brief コンストラクタ
	 */
	CachePacketQuestDataRequest()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	CachePacketQuestDataRequest(u32 InClientId, u32 InCharacterId)
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

#endif		// #ifndef __CACHEPACKETQUESTDATAREQUEST_H__
