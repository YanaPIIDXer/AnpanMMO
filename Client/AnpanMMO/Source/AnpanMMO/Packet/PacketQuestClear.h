/**
 * @file PacketQuestClear.h
 * @brief クエストクリア
 * @author NativePacketGenerator
 */

#ifndef __PACKETQUESTCLEAR_H__
#define __PACKETQUESTCLEAR_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief クエストクリア
 */
class PacketQuestClear  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @returns パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::QuestClear; }

	

	//! 
u32 QuestId;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketQuestClear()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketQuestClear(u32 InQuestId)
	{
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
		pStream->Serialize(&QuestId);
		
		return true;
	}
};

#endif		// #ifndef __PACKETQUESTCLEAR_H__
