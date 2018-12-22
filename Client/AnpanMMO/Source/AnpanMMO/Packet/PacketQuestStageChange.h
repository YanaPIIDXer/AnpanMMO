/**
 * @file PacketQuestStageChange.h
 * @brief クエストステージ進行
 * @author NativePacketGenerator
 */

#ifndef __PACKETQUESTSTAGECHANGE_H__
#define __PACKETQUESTSTAGECHANGE_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief クエストステージ進行
 */
class PacketQuestStageChange  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::QuestStageChange; }

	

	//! クエストＩＤ
	u32 QuestId;
	//! ステージ番号
	u32 StageNo;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketQuestStageChange()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketQuestStageChange(u32 InQuestId, u32 InStageNo)
	{
		QuestId = InQuestId;
		StageNo = InStageNo;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief シリアライズ
	 * @param[in] pStream ストリーム
	 * @return 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&QuestId);
		pStream->Serialize(&StageNo);
		
		return true;
	}
};

#endif		// #ifndef __PACKETQUESTSTAGECHANGE_H__
