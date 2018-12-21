/**
 * @file PacketNPCTalk.h
 * @brief 会話開始
 * @author NativePacketGenerator
 */

#ifndef __PACKETNPCTALK_H__
#define __PACKETNPCTALK_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief 会話開始
 */
class PacketNPCTalk  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::NPCTalk; }

	

	//! ＮＰＣマスタＩＤ
	u32 MasterId;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketNPCTalk()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketNPCTalk(u32 InMasterId)
	{
		MasterId = InMasterId;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief シリアライズ
	 * @param[in] pStream ストリーム
	 * @retrn 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&MasterId);
		
		return true;
	}
};

#endif		// #ifndef __PACKETNPCTALK_H__
