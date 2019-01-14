/**
 * @file PacketLevelUp.h
 * @brief ���x���A�b�v�p�P�b�g
 * @author NativePacketGenerator
 */

#ifndef __PACKETLEVELUP_H__
#define __PACKETLEVELUP_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief ���x���A�b�v�p�P�b�g
 */
class PacketLevelUp  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::LevelUp; }

	

	//! ���x��
	u32 Level;
	//! �ő�g�o
	u32 MaxHp;
	//! ��b�ő�g�o
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
	//! �o���l
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
	 * @brief �V���A���C�Y
	 * @param[in] pStream �X�g���[��
	 * @return ����������true��Ԃ��B
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
