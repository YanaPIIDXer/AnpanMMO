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
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::LevelUp; }

	

	//! 
u32 Level;
	//! 
s32 MaxHp;
	//! 
s32 Atk;
	//! 
s32 Def;
	//! 
s32 ResultExp;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketLevelUp()
	{
	}

	/**
	 * @brief �R���X�g���N�^
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
	 * @brief �V���A���C�Y
	 * @param in pStream �X�g���[��
	 * @retrns ����������true��Ԃ��B
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
