/**
 * @file CachePacketQuestRetireRequest.h
 * @brief クエスト破棄リクエスト
 * @author NativePacketGenerator
 */

#ifndef __CACHEPACKETQUESTRETIREREQUEST_H__
#define __CACHEPACKETQUESTRETIREREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "CacheServerPacketID.h"


/**
 * @brief クエスト破棄リクエスト
 */
class CachePacketQuestRetireRequest  : public ProcessPacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return CachePacketID::CacheQuestRetireRequest; }

	

	//! キャラクタID
	u32 CharacterId;
	//! クエストID
	u32 QuestId;
	

	/**
	 * @brief コンストラクタ
	 */
	CachePacketQuestRetireRequest()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	CachePacketQuestRetireRequest(u32 InClientId, u32 InCharacterId, u32 InQuestId)
	{
		ClientId = InClientId;
		CharacterId = InCharacterId;
		QuestId = InQuestId;
		
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
		pStream->Serialize(&QuestId);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETQUESTRETIREREQUEST_H__
