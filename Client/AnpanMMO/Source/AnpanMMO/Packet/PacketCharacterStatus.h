/**
 * @file PacketCharacterStatus.h
 * @brief �L�����N�^�p�����[�^�p�P�b�g
 * @author NativePacketGenerator
 */

#ifndef __PACKETCHARACTERSTATUS_H__
#define __PACKETCHARACTERSTATUS_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief �L�����N�^�p�����[�^�p�P�b�g
 */
class PacketCharacterStatus  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::CharacterStatus; }

	

	//! UUID
	u32 Uuid;
	//! ���O
	std::string Name;
	//! �W���u
	u8 Job;
	//! ���x��
	u32 Level;
	//! HP
	u32 Hp;
	//! �ő�HP
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
	//! �o���l
	u32 Exp;
	//! �S�[���h
	u32 Gold;
	//! �E�葕��
	u32 RightEquip;
	//! ���葕��
	u32 LeftEquip;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketCharacterStatus()
	{
	}

	/**
	 * @brief �R���X�g���N�^
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
	 * @brief �V���A���C�Y
	 * @param[in] pStream �X�g���[��
	 * @return ����������true��Ԃ��B
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
