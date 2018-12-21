/**
 * @file CachePacketQuestDataResponse.h
 * @brief クエストデータレスポンス
 * @author NativePacketGenerator
 */

#ifndef __CACHEPACKETQUESTDATARESPONSE_H__
#define __CACHEPACKETQUESTDATARESPONSE_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "FlexArray.h"
#include "QuestData.h"
#include "CacheServerPacketID.h"


/**
 * @brief クエストデータレスポンス
 */
class CachePacketQuestDataResponse  : public ProcessPacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return CachePacketID::CacheQuestDataResponse; }

	enum ResultCode
	{
		//! 成功
		Success,
		//! エラー
		Error,
	};

	//! 結果
	u8 Result;
	//! クエストリスト
	FlexArray<QuestData> Quests;
	//! アクティブクエストＩＤ
	u32 ActiveQuestId;
	

	/**
	 * @brief コンストラクタ
	 */
	CachePacketQuestDataResponse()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	CachePacketQuestDataResponse(u32 InClientId, u8 InResult, FlexArray<QuestData> InQuests, u32 InActiveQuestId)
	{
		ClientId = InClientId;
		Result = InResult;
		Quests = InQuests;
		ActiveQuestId = InActiveQuestId;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief シリアライズ
	 * @param[in] pStream ストリーム
	 * @retrn 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		ProcessPacketBase::Serialize(pStream);
		pStream->Serialize(&Result);
		Quests.Serialize(pStream);
		pStream->Serialize(&ActiveQuestId);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETQUESTDATARESPONSE_H__
