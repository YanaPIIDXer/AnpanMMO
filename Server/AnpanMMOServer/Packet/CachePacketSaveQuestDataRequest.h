/**
 * @file CachePacketSaveQuestDataRequest.h
 * @brief クエストデータ保存リクエスト
 * @author NativePacketGenerator
 */

#ifndef __CACHEPACKETSAVEQUESTDATAREQUEST_H__
#define __CACHEPACKETSAVEQUESTDATAREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "QuestData.h"
#include "CacheServerPacketID.h"


/**
 * @brief クエストデータ保存リクエスト
 */
class CachePacketSaveQuestDataRequest  : public ProcessPacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @returns パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return CachePacketID::CacheSaveQuestDataRequest; }

	

	//! キャラクタＩＤ
	u32 CharacterId;
	//! クエストデータ
	QuestData Data;
	

	/**
	 * @brief コンストラクタ
	 */
	CachePacketSaveQuestDataRequest()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	CachePacketSaveQuestDataRequest(u32 InClientId, u32 InCharacterId, QuestData InData)
	{
		ClientId = InClientId;
		CharacterId = InCharacterId;
		Data = InData;
		
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
		Data.Serialize(pStream);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETSAVEQUESTDATAREQUEST_H__
