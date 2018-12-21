/**
 * @file PacketHeal.h
 * @brief 回復
 * @author NativePacketGenerator
 */

#ifndef __PACKETHEAL_H__
#define __PACKETHEAL_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief 回復
 */
class PacketHeal  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @returns パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::Heal; }

	

	//! ターゲットタイプ
	u8 TargetType;
	//! ターゲットのUUID
	u32 TargetUuid;
	//! 回復量
	s32 HealValue;
	//! 回復後のHP
	s32 ResultHp;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketHeal()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketHeal(u8 InTargetType, u32 InTargetUuid, s32 InHealValue, s32 InResultHp)
	{
		TargetType = InTargetType;
		TargetUuid = InTargetUuid;
		HealValue = InHealValue;
		ResultHp = InResultHp;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief シリアライズ
	 * @param[in] pStream ストリーム
	 * @retrns 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&TargetType);
		pStream->Serialize(&TargetUuid);
		pStream->Serialize(&HealValue);
		pStream->Serialize(&ResultHp);
		
		return true;
	}
};

#endif		// #ifndef __PACKETHEAL_H__
