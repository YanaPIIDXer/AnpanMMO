/**
 * @file PacketSkillActivate.h
 * @brief スキル発動
 * @author NativePacketGenerator
 */

#ifndef __PACKETSKILLACTIVATE_H__
#define __PACKETSKILLACTIVATE_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief スキル発動
 */
class PacketSkillActivate  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::SkillActivate; }

	

	//! 
u8 CharacterType;
	//! 
u32 CharacterUuid;
	//! 
u32 SkillId;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketSkillActivate()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketSkillActivate(u8 InCharacterType, u32 InCharacterUuid, u32 InSkillId)
	{
		CharacterType = InCharacterType;
		CharacterUuid = InCharacterUuid;
		SkillId = InSkillId;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief �V���A���C�Y
	 * @param in pStream �X�g���[��
	 * @retrns ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&CharacterType);
		pStream->Serialize(&CharacterUuid);
		pStream->Serialize(&SkillId);
		
		return true;
	}
};

#endif		// #ifndef __PACKETSKILLACTIVATE_H__
