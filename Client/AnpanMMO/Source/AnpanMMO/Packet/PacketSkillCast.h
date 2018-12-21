/**
 * @file PacketSkillCast.h
 * @brief スキル詠唱開始
 * @author NativePacketGenerator
 */

#ifndef __PACKETSKILLCAST_H__
#define __PACKETSKILLCAST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief スキル詠唱開始
 */
class PacketSkillCast  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::SkillCast; }

	

	//! 
u32 SkillId;
	//! 
u8 CharacterType;
	//! 
u32 CharacterUuid;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketSkillCast()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketSkillCast(u32 InSkillId, u8 InCharacterType, u32 InCharacterUuid)
	{
		SkillId = InSkillId;
		CharacterType = InCharacterType;
		CharacterUuid = InCharacterUuid;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief �V���A���C�Y
	 * @param in pStream �X�g���[��
	 * @retrns ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&SkillId);
		pStream->Serialize(&CharacterType);
		pStream->Serialize(&CharacterUuid);
		
		return true;
	}
};

#endif		// #ifndef __PACKETSKILLCAST_H__
