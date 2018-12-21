/**
 * @file PacketSkillCastFinish.h
 * @brief �X�L���r������
 * @author NativePacketGenerator
 */

#ifndef __PACKETSKILLCASTFINISH_H__
#define __PACKETSKILLCASTFINISH_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief �X�L���r������
 */
class PacketSkillCastFinish  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::SkillCastFinish; }

	

	//! 
u8 CharacterType;
	//! 
u32 CharacterUuid;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketSkillCastFinish()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketSkillCastFinish(u8 InCharacterType, u32 InCharacterUuid)
	{
		CharacterType = InCharacterType;
		CharacterUuid = InCharacterUuid;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief �V���A���C�Y
	 * @param[in] pStream �X�g���[��
	 * @retrns ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&CharacterType);
		pStream->Serialize(&CharacterUuid);
		
		return true;
	}
};

#endif		// #ifndef __PACKETSKILLCASTFINISH_H__
