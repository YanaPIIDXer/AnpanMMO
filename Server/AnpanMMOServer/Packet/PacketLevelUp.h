/**
 * @file PacketLevelUp.h
 * @brief レベルアップ
 * @author NativePacketGenerator
 */

#ifndef __PACKETLEVELUP_H__
#define __PACKETLEVELUP_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief レベルアップ
 */
class PacketLevelUp  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::LevelUp; }

	

	//! レベル
	u32 Level;
	//! 最大ＨＰ
	s32 MaxHp;
	//! 攻撃力
	s32 Atk;
	//! 防御力
	s32 Def;
	//! 経験値
	s32 ResultExp;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketLevelUp()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketLevelUp(u32 InLevel, s32 InMaxHp, s32 InAtk, s32 InDef, s32 InResultExp)
	{
		Level = InLevel;
		MaxHp = InMaxHp;
		Atk = InAtk;
		Def = InDef;
		ResultExp = InResultExp;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief シリアライズ
	 * @param[in] pStream ストリーム
	 * @return 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Level);
		pStream->Serialize(&MaxHp);
		pStream->Serialize(&Atk);
		pStream->Serialize(&Def);
		pStream->Serialize(&ResultExp);
		
		return true;
	}
};

#endif		// #ifndef __PACKETLEVELUP_H__
