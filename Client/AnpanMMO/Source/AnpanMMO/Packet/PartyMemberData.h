/**
 * @file PartyMemberData.h
 * @brief �p�[�e�B�����o���p�P�b�g
 * @author NativePacketGenerator
 */

#ifndef __PARTYMEMBERDATA_H__
#define __PARTYMEMBERDATA_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"


/**
 * @brief �p�[�e�B�����o���p�P�b�g
 */
class PartyMemberData 
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	

	

	//! UUID
	u32 Uuid;
	//! �L�����N�^��
	std::string CharacterName;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PartyMemberData()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PartyMemberData(u32 InUuid, std::string InCharacterName)
	{
		Uuid = InUuid;
		CharacterName = InCharacterName;
		
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
		pStream->Serialize(&CharacterName);
		
		return true;
	}
};

#endif		// #ifndef __PARTYMEMBERDATA_H__
