/**
 * @file PacketQuestRetireResponse.h
 * @brief クエスト破棄レスポンス
 * @author NativePacketGenerator
 */

#ifndef __PACKETQUESTRETIRERESPONSE_H__
#define __PACKETQUESTRETIRERESPONSE_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief クエスト破棄レスポンス
 */
class PacketQuestRetireResponse  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @returns パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::QuestRetireResponse; }

	enum ResultCode
	{
		//! 成功
		Success,
		//! メインクエスト
		MainQuest,
		//! エラー
		Error,
	};

	//! クエストＩＤ
	u32 QuestId;
	//! 結果
	u8 Result;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketQuestRetireResponse()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketQuestRetireResponse(u32 InQuestId, u8 InResult)
	{
		QuestId = InQuestId;
		Result = InResult;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief シリアライズ
	 * @param[in] pStream ストリーム
	 * @retrns 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&QuestId);
		pStream->Serialize(&Result);
		
		return true;
	}
};

#endif		// #ifndef __PACKETQUESTRETIRERESPONSE_H__
