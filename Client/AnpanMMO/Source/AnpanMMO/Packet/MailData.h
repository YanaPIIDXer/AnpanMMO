/**
 * @file MailData.h
 * @brief ���[���f�[�^�p�P�b�g
 * @author NativePacketGenerator
 */

#ifndef __MAILDATA_H__
#define __MAILDATA_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"


/**
 * @brief ���[���f�[�^�p�P�b�g
 */
class MailData 
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	

	enum AttachmentKind
	{
		//! ����
		None,
		//! �A�C�e��
		Item,
		//! �S�[���h
		Gold,
	};enum MailFlag
	{
		//! ����
		NotRead,
		//! ����
		Read,
		//! �Y�t���󒍍ς�
		RecvAttachment,
	};

	//! �h�c
	u32 Id;
	//! ����
	std::string Subject;
	//! �{��
	std::string Body;
	//! �Y�t���^�C�v
	u8 AttachmentType;
	//! �Y�t���h�c
	u32 AttachmentId;
	//! �Y�t����
	u32 AttachmentCount;
	//! �t���O
	u8 Flag;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	MailData()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	MailData(u32 InId, std::string InSubject, std::string InBody, u8 InAttachmentType, u32 InAttachmentId, u32 InAttachmentCount, u8 InFlag)
	{
		Id = InId;
		Subject = InSubject;
		Body = InBody;
		AttachmentType = InAttachmentType;
		AttachmentId = InAttachmentId;
		AttachmentCount = InAttachmentCount;
		Flag = InFlag;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief �V���A���C�Y
	 * @param[in] pStream �X�g���[��
	 * @return ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Id);
		pStream->Serialize(&Subject);
		pStream->Serialize(&Body);
		pStream->Serialize(&AttachmentType);
		pStream->Serialize(&AttachmentId);
		pStream->Serialize(&AttachmentCount);
		pStream->Serialize(&Flag);
		
		return true;
	}
};

#endif		// #ifndef __MAILDATA_H__
