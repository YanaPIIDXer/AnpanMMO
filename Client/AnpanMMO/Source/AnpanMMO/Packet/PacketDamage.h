/**
 * @file PacketDamage.h
 * @brief ダメージパケット
 * @author NativePacketGenerator
 */

#ifndef __PACKETDAMAGE_H__
#define __PACKETDAMAGE_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief ダメージパケット
 */
class PacketDamage  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::Damage; }

	

	//! ターゲットタイプ
	u8 TargetType;
	//! ターゲットのUUID
	u32 TargetUuid;
	//! ダメージ量
	s32 DamageValue;
	//! ダメージ後のHP
	s32 ResultHp;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketDamage()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketDamage(u8 InTargetType, u32 InTargetUuid, s32 InDamageValue, s32 InResultHp)
	{
		TargetType = InTargetType;
		TargetUuid = InTargetUuid;
		DamageValue = InDamageValue;
		ResultHp = InResultHp;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief シリアライズ
	 * @param[in] pStream ストリーム
	 * @return 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&TargetType);
		pStream->Serialize(&TargetUuid);
		pStream->Serialize(&DamageValue);
		pStream->Serialize(&ResultHp);
		
		return true;
	}
};

#endif		// #ifndef __PACKETDAMAGE_H__
