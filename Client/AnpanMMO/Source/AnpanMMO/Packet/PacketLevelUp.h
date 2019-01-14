/**
 * @file PacketLevelUp.h
 * @brief レベルアップパケット
 * @author NativePacketGenerator
 */

#ifndef __PACKETLEVELUP_H__
#define __PACKETLEVELUP_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief レベルアップパケット
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
	u32 MaxHp;
	//! 基礎最大ＨＰ
	u32 BaseMaxHp;
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
	PacketLevelUp(u32 InLevel, u32 InMaxHp, u32 InBaseMaxHp, u32 InStr, u32 InDef, u32 InInt, u32 InMnd, u32 InVit, s32 InResultExp)
	{
		Level = InLevel;
		MaxHp = InMaxHp;
		BaseMaxHp = InBaseMaxHp;
		Str = InStr;
		Def = InDef;
		Int = InInt;
		Mnd = InMnd;
		Vit = InVit;
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
		pStream->Serialize(&BaseMaxHp);
		pStream->Serialize(&Str);
		pStream->Serialize(&Def);
		pStream->Serialize(&Int);
		pStream->Serialize(&Mnd);
		pStream->Serialize(&Vit);
		pStream->Serialize(&ResultExp);
		
		return true;
	}
};

#endif		// #ifndef __PACKETLEVELUP_H__
