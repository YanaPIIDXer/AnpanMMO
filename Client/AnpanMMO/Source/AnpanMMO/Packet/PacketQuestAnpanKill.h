/**
 * @file PacketQuestAnpanKill.h
 * @brief クエストアンパンキル
 * @author NativePacketGenerator
 */

#ifndef __PACKETQUESTANPANKILL_H__
#define __PACKETQUESTANPANKILL_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief クエストアンパンキル
 */
class PacketQuestAnpanKill  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @returns パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::QuestAnpanKill; }

	

	//! クエストＩＤ
	u32 QuestId;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketQuestAnpanKill()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketQuestAnpanKill(u32 InQuestId)
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

#endif		// #ifndef __PACKETQUESTANPANKILL_H__
