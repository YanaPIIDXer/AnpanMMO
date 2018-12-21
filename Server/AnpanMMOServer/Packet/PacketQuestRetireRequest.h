/**
 * @file PacketQuestRetireRequest.h
 * @brief クエスト破棄リクエスト
 * @author NativePacketGenerator
 */

#ifndef __PACKETQUESTRETIREREQUEST_H__
#define __PACKETQUESTRETIREREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief クエスト破棄リクエスト
 */
class PacketQuestRetireRequest  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @returns パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::QuestRetireRequest; }

	

	//! 
u32 QuestId;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketQuestRetireRequest()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketQuestRetireRequest(u32 InQuestId)
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

#endif		// #ifndef __PACKETQUESTRETIREREQUEST_H__
