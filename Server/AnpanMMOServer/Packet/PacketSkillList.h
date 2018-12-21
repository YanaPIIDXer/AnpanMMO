/**
 * @file PacketSkillList.h
 * @brief �X�L�����X�g
 * @author NativePacketGenerator
 */

#ifndef __PACKETSKILLLIST_H__
#define __PACKETSKILLLIST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief �X�L�����X�g
 */
class PacketSkillList  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::SkillList; }

	

	//! �ʏ�U���h�c
	u32 NormalAttack;
	//! �X�L���h�c�P
	u32 Skill1;
	//! �X�L���h�c�Q
	u32 Skill2;
	//! �X�L���h�c�R
	u32 Skill3;
	//! �X�L���h�c�S
	u32 Skill4;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketSkillList()
	{
	}

	/**
	 * @brief �R���X�g���N�^
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
	 * @brief �V���A���C�Y
	 * @param[in] pStream �X�g���[��
	 * @retrn ����������true��Ԃ��B
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
