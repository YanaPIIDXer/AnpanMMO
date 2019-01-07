/**
 * @file WordCheckPacketChatRequest.h
 * @brief ���[�h�`�F�b�N�v���p�P�b�g
 * @author NativePacketGenerator
 */

#ifndef __WORDCHECKPACKETCHATREQUEST_H__
#define __WORDCHECKPACKETCHATREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "WordCheckServerPacketID.h"


/**
 * @brief ���[�h�`�F�b�N�v���p�P�b�g
 */
class WordCheckPacketChatRequest  : public ProcessPacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return WordCheckPacketID::WordCheckChatRequest; }

	

	//! �^�C�v
	u8 Type;
	//! ���b�Z�[�W
	std::string Message;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	WordCheckPacketChatRequest()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	WordCheckPacketChatRequest(u32 InClientId, u8 InType, std::string InMessage)
	{
		ClientId = InClientId;
		Type = InType;
		Message = InMessage;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief �V���A���C�Y
	 * @param[in] pStream �X�g���[��
	 * @return ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		ProcessPacketBase::Serialize(pStream);
		pStream->Serialize(&Type);
		pStream->Serialize(&Message);
		
		return true;
	}
};

#endif		// #ifndef __WORDCHECKPACKETCHATREQUEST_H__
