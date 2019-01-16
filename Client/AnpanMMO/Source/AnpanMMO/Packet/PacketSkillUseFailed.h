/**
 * @file PacketSkillUseFailed.h
 * @brief スキル使用失敗パケット
 * @author NativePacketGenerator
 */

#ifndef __PACKETSKILLUSEFAILED_H__
#define __PACKETSKILLUSEFAILED_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief スキル使用失敗パケット
 */
class PacketSkillUseFailed  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::SkillUseFailed; }

	enum ReasonType
	{
		//! リキャスト中
		RecastTime,
		//! 無効なスキル
		InvalidSkill,
		//! キャンセル
		Cancel,
		//! ターゲット消失
		TargetDisappeared,
	};

	//! 失敗理由
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
	 * @param[in] pStream ストリーム
	 * @return 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Reason);
		
		return true;
	}
};

#endif		// #ifndef __PACKETSKILLUSEFAILED_H__
