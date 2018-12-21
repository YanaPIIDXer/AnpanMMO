/**
 * @file PacketQuestData.h
 * @brief クエストデータリスト
 * @author NativePacketGenerator
 */

#ifndef __PACKETQUESTDATA_H__
#define __PACKETQUESTDATA_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "FlexArray.h"
#include "QuestData.h"
#include "PacketID.h"


/**
 * @brief クエストデータリスト
 */
class PacketQuestData  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @returns パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::QuestData; }

	

	//! クエストリスト
	FlexArray<QuestData> Quests;
	//! アクティブクエストＩＤ
	u32 ActiveQuestId;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketQuestData()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketQuestData(FlexArray<QuestData> InQuests, u32 InActiveQuestId)
	{
		Quests = InQuests;
		ActiveQuestId = InActiveQuestId;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief シリアライズ
	 * @param[in] pStream ストリーム
	 * @retrns 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		Quests.Serialize(pStream);
		pStream->Serialize(&ActiveQuestId);
		
		return true;
	}
};

#endif		// #ifndef __PACKETQUESTDATA_H__
