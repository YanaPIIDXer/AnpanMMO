/**
 * @file PacketSaveActiveQuest.h
 * @brief アクティブクエスト保存パケット
 * @author NativePacketGenerator
 */

#ifndef __PACKETSAVEACTIVEQUEST_H__
#define __PACKETSAVEACTIVEQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief アクティブクエスト保存パケット
 */
class PacketSaveActiveQuest  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::SaveActiveQuest; }

	

	//! クエストＩＤ
	u32 QuestId;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketSaveActiveQuest()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketSaveActiveQuest(u32 InQuestId)
	{
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
		pStream->Serialize(&QuestId);
		
		return true;
	}
};

#endif		// #ifndef __PACKETSAVEACTIVEQUEST_H__
