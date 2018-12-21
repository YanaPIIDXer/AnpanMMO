/**
 * @file CachePacketSaveActiveQuestRequest.h
 * @brief アクティブクエスト保存リクエスト
 * @author NativePacketGenerator
 */

#ifndef __CACHEPACKETSAVEACTIVEQUESTREQUEST_H__
#define __CACHEPACKETSAVEACTIVEQUESTREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "CacheServerPacketID.h"


/**
 * @brief アクティブクエスト保存リクエスト
 */
class CachePacketSaveActiveQuestRequest  : public ProcessPacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @returns パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return CachePacketID::CacheSaveActiveQuestRequest; }

	

	//! キャラクタID
	u32 CharacterId;
	//! クエストID
	u32 QuestId;
	

	/**
	 * @brief コンストラクタ
	 */
	CachePacketSaveActiveQuestRequest()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	CachePacketSaveActiveQuestRequest(u32 InClientId, u32 InCharacterId, u32 InQuestId)
	{
		ClientId = InClientId;
		CharacterId = InCharacterId;
		QuestId = InQuestId;
		
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
		pStream->Serialize(&QuestId);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETSAVEACTIVEQUESTREQUEST_H__
