/**
 * @file PacketSkillList.h
 * @brief スキルリスト
 * @author NativePacketGenerator
 */

#ifndef __PACKETSKILLLIST_H__
#define __PACKETSKILLLIST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief スキルリスト
 */
class PacketSkillList  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::SkillList; }

	

	//! 通常攻撃ＩＤ
	u32 NormalAttack;
	//! スキルＩＤ１
	u32 Skill1;
	//! スキルＩＤ２
	u32 Skill2;
	//! スキルＩＤ３
	u32 Skill3;
	//! スキルＩＤ４
	u32 Skill4;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketSkillList()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketSkillList(u32 InNormalAttack, u32 InSkill1, u32 InSkill2, u32 InSkill3, u32 InSkill4)
	{
		NormalAttack = InNormalAttack;
		Skill1 = InSkill1;
		Skill2 = InSkill2;
		Skill3 = InSkill3;
		Skill4 = InSkill4;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief シリアライズ
	 * @param[in] pStream ストリーム
	 * @retrn 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&NormalAttack);
		pStream->Serialize(&Skill1);
		pStream->Serialize(&Skill2);
		pStream->Serialize(&Skill3);
		pStream->Serialize(&Skill4);
		
		return true;
	}
};

#endif		// #ifndef __PACKETSKILLLIST_H__
