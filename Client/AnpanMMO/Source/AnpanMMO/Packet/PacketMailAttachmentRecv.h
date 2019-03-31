/**
 * @file PacketMailAttachmentRecv.h
 * @brief �Y�t����M�p�P�b�g
 * @author NativePacketGenerator
 */

#ifndef __PACKETMAILATTACHMENTRECV_H__
#define __PACKETMAILATTACHMENTRECV_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief �Y�t����M�p�P�b�g
 */
class PacketMailAttachmentRecv  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::MailAttachmentRecv; }

	

	//! �h�c
	u32 Id;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketMailAttachmentRecv()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketMailAttachmentRecv(u32 InId)
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

#endif		// #ifndef __PACKETMAILATTACHMENTRECV_H__
