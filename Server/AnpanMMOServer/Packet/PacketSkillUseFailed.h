/**
 * @file PacketSkillUseFailed.h
 * @brief スキル使用失敗
 * @author NativePacketGenerator
 */

#ifndef __PACKETSKILLUSEFAILED_H__
#define __PACKETSKILLUSEFAILED_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief スキル使用失敗
 */
class PacketSkillUseFailed  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @returns パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::SkillUseFailed; }

	enum ReasonType
	{
		//! 
		RecastTime = リキャスト中,
		//! 
		Cancel = キャンセル,
		//! 
		TargetDisappeared = ターゲット消失,
	};

	//! 
u8 Reason;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketSkillUseFailed()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketSkillUseFailed(u8 InReason)
	{
		Reason = InReason;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief シリアライズ
	 * @param in pStream ストリーム
	 * @retrns 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Reason);
		
		return true;
	}
};

#endif		// #ifndef __PACKETSKILLUSEFAILED_H__
