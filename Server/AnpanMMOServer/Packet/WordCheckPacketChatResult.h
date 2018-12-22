/**
 * @file WordCheckPacketChatResult.h
 * @brief ���[�h�`�F�b�N����
 * @author NativePacketGenerator
 */

#ifndef __WORDCHECKPACKETCHATRESULT_H__
#define __WORDCHECKPACKETCHATRESULT_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "WordCheckServerPacketID.h"


/**
 * @brief ���[�h�`�F�b�N����
 */
class WordCheckPacketChatResult  : public ProcessPacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return WordCheckPacketID::WordCheckChatResult; }

	

	//! �^�C�v
	u8 Type;
	//! ���b�Z�[�W
	std::string Message;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	WordCheckPacketChatResult()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	WordCheckPacketChatResult(u32 InClientId, u8 InType, std::string InMessage)
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

#endif		// #ifndef __WORDCHECKPACKETCHATRESULT_H__
