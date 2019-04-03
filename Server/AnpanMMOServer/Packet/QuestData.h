/**
 * @file QuestData.h
 * @brief クエストデータパケット
 * @author NativePacketGenerator
 */

#ifndef __QUESTDATA_H__
#define __QUESTDATA_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"


/**
 * @brief クエストデータパケット
 */
class QuestData 
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	

	enum StateType
	{
		//! 進行中
		Active,
		//! クリア済み
		Cleared,
	};

	//! クエストＩＤ
	u32 QuestId;
	//! ステージ番号
	u32 StageNo;
	//! 殺害数
	u32 KillCount;
	//! ステート
	u8 State;
	

	/**
	 * @brief コンストラクタ
	 */
	QuestData()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	QuestData(u32 InQuestId, u32 InStageNo, u32 InKillCount, u8 InState)
	{
		QuestId = InQuestId;
		StageNo = InStageNo;
		KillCount = InKillCount;
		State = InState;
		
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
		pStream->Serialize(&KillCount);
		pStream->Serialize(&State);
		
		return true;
	}
};

#endif		// #ifndef __QUESTDATA_H__
