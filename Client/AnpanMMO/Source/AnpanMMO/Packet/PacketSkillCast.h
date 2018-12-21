/**
 * @file PacketSkillCast.h
 * @brief �X�L���r���J�n
 * @author NativePacketGenerator
 */

#ifndef __PACKETSKILLCAST_H__
#define __PACKETSKILLCAST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief �X�L���r���J�n
 */
class PacketSkillCast  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::SkillCast; }

	

	//! �X�L���h�c
	u32 SkillId;
	//! �L�����N�^�^�C�v
	u8 CharacterType;
	//! �L�����N�^�t�t�h�c
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
	 * @param[in] pStream �X�g���[��
	 * @retrn ����������true��Ԃ��B
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
