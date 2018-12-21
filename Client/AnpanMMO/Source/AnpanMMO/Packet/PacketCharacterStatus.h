/**
 * @file PacketCharacterStatus.h
 * @brief �L�����N�^�p�����[�^
 * @author NativePacketGenerator
 */

#ifndef __PACKETCHARACTERSTATUS_H__
#define __PACKETCHARACTERSTATUS_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief �L�����N�^�p�����[�^
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
	s32 Hp;
	//! �ő�HP
	s32 MaxHp;
	//! �U����
	s32 Atk;
	//! �h���
	s32 Def;
	//! �o���l
	s32 Exp;
	//! �S�[���h
	u32 Gold;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketCharacterStatus()
	{
	}

	/**
	 * @brief �R���X�g���N�^
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
	 * @brief �V���A���C�Y
	 * @param[in] pStream �X�g���[��
	 * @retrn ����������true��Ԃ��B
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
