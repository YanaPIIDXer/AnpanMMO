/**
 * @file PacketMailAttachmentRecvRequest.h
 * @brief �Y�t����M���N�G�X�g�p�P�b�g
 * @author NativePacketGenerator
 */

#ifndef __PACKETMAILATTACHMENTRECVREQUEST_H__
#define __PACKETMAILATTACHMENTRECVREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief �Y�t����M���N�G�X�g�p�P�b�g
 */
class PacketMailAttachmentRecvRequest  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::MailAttachmentRecvRequest; }

	

	//! �h�c
	u32 Id;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketMailAttachmentRecvRequest()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketMailAttachmentRecvRequest(u32 InId)
	{
		Id = InId;
		
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
		
		return true;
	}
};

#endif		// #ifndef __PACKETMAILATTACHMENTRECVREQUEST_H__
