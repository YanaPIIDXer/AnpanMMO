/**
 * @file NoticeData.h
 * @brief �ʒm�f�[�^�p�P�b�g
 * @author NativePacketGenerator
 */

#ifndef __NOTICEDATA_H__
#define __NOTICEDATA_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"


/**
 * @brief �ʒm�f�[�^�p�P�b�g
 */
class NoticeData 
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	

	enum NoticeType
	{
		//! �p�[�e�B���U
		PartyInvide,
	};

	//! �^�C�v
	u8 Type;
	//! �J�X�^�}�h�c
	u32 CustomerId;
	//! �L�����N�^��
	std::string CharacterName;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	NoticeData()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	NoticeData(u8 InType, u32 InCustomerId, std::string InCharacterName)
	{
		Type = InType;
		CustomerId = InCustomerId;
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
		pStream->Serialize(&Type);
		pStream->Serialize(&CustomerId);
		pStream->Serialize(&CharacterName);
		
		return true;
	}
};

#endif		// #ifndef __NOTICEDATA_H__
