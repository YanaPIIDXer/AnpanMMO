/**
 * @file PacketSkillUse.h
 * @brief スキル使用
 * @author NativePacketGenerator
 */

#ifndef __PACKETSKILLUSE_H__
#define __PACKETSKILLUSE_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief スキル使用
 */
class PacketSkillUse  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::SkillUse; }

	

	//! スキルＩＤ
	u32 SkillId;
	//! ターゲットタイプ
	u8 TargetType;
	//! ターゲットＵＵＩＤ
	u32 TargetUuid;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketSkillUse()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketSkillUse(u32 InSkillId, u8 InTargetType, u32 InTargetUuid)
	{
		SkillId = InSkillId;
		TargetType = InTargetType;
		TargetUuid = InTargetUuid;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief シリアライズ
	 * @param[in] pStream ストリーム
	 * @retrn 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&SkillId);
		pStream->Serialize(&TargetType);
		pStream->Serialize(&TargetUuid);
		
		return true;
	}
};

#endif		// #ifndef __PACKETSKILLUSE_H__
