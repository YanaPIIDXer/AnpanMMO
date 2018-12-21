/**
 * @file PacketCharacterStatus.h
 * @brief キャラクタパラメータ
 * @author NativePacketGenerator
 */

#ifndef __PACKETCHARACTERSTATUS_H__
#define __PACKETCHARACTERSTATUS_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief キャラクタパラメータ
 */
class PacketCharacterStatus  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::CharacterStatus; }

	

	//! UUID
	u32 Uuid;
	//! 名前
	std::string Name;
	//! ジョブ
	u8 Job;
	//! レベル
	u32 Level;
	//! HP
	s32 Hp;
	//! 最大HP
	s32 MaxHp;
	//! 攻撃力
	s32 Atk;
	//! 防御力
	s32 Def;
	//! 経験値
	s32 Exp;
	//! ゴールド
	u32 Gold;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketCharacterStatus()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketCharacterStatus(u32 InUuid, std::string InName, u8 InJob, u32 InLevel, s32 InHp, s32 InMaxHp, s32 InAtk, s32 InDef, s32 InExp, u32 InGold)
	{
		Uuid = InUuid;
		Name = InName;
		Job = InJob;
		Level = InLevel;
		Hp = InHp;
		MaxHp = InMaxHp;
		Atk = InAtk;
		Def = InDef;
		Exp = InExp;
		Gold = InGold;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief シリアライズ
	 * @param[in] pStream ストリーム
	 * @retrn 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Uuid);
		pStream->Serialize(&Name);
		pStream->Serialize(&Job);
		pStream->Serialize(&Level);
		pStream->Serialize(&Hp);
		pStream->Serialize(&MaxHp);
		pStream->Serialize(&Atk);
		pStream->Serialize(&Def);
		pStream->Serialize(&Exp);
		pStream->Serialize(&Gold);
		
		return true;
	}
};

#endif		// #ifndef __PACKETCHARACTERSTATUS_H__
