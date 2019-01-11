/**
 * @file PacketCharacterStatus.h
 * @brief キャラクタパラメータパケット
 * @author NativePacketGenerator
 */

#ifndef __PACKETCHARACTERSTATUS_H__
#define __PACKETCHARACTERSTATUS_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief キャラクタパラメータパケット
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
	u32 Hp;
	//! 最大HP
	u32 MaxHp;
	//! STR
	u32 Str;
	//! DEF
	u32 Def;
	//! INT
	u32 Int;
	//! MND
	u32 Mnd;
	//! VIT
	u32 Vit;
	//! 経験値
	u32 Exp;
	//! ゴールド
	u32 Gold;
	//! 右手装備
	u32 RightEquip;
	//! 左手装備
	u32 LeftEquip;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketCharacterStatus()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketCharacterStatus(u32 InUuid, std::string InName, u8 InJob, u32 InLevel, u32 InHp, u32 InMaxHp, u32 InStr, u32 InDef, u32 InInt, u32 InMnd, u32 InVit, u32 InExp, u32 InGold, u32 InRightEquip, u32 InLeftEquip)
	{
		Uuid = InUuid;
		Name = InName;
		Job = InJob;
		Level = InLevel;
		Hp = InHp;
		MaxHp = InMaxHp;
		Str = InStr;
		Def = InDef;
		Int = InInt;
		Mnd = InMnd;
		Vit = InVit;
		Exp = InExp;
		Gold = InGold;
		RightEquip = InRightEquip;
		LeftEquip = InLeftEquip;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief シリアライズ
	 * @param[in] pStream ストリーム
	 * @return 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Uuid);
		pStream->Serialize(&Name);
		pStream->Serialize(&Job);
		pStream->Serialize(&Level);
		pStream->Serialize(&Hp);
		pStream->Serialize(&MaxHp);
		pStream->Serialize(&Str);
		pStream->Serialize(&Def);
		pStream->Serialize(&Int);
		pStream->Serialize(&Mnd);
		pStream->Serialize(&Vit);
		pStream->Serialize(&Exp);
		pStream->Serialize(&Gold);
		pStream->Serialize(&RightEquip);
		pStream->Serialize(&LeftEquip);
		
		return true;
	}
};

#endif		// #ifndef __PACKETCHARACTERSTATUS_H__
