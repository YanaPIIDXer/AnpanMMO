/**
 * @file PacketMailAttachmentRecvResult.h
 * @brief �Y�t����M���ʃp�P�b�g
 * @author NativePacketGenerator
 */

#ifndef __PACKETMAILATTACHMENTRECVRESULT_H__
#define __PACKETMAILATTACHMENTRECVRESULT_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief �Y�t����M���ʃp�P�b�g
 */
class PacketMailAttachmentRecvResult  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::MailAttachmentRecvResult; }

	enum ResultCode
	{
		//! ����
		Success,
		//! ��M�ς�
		AlreadyRecv,
		//! �G���[
		Error,
	};

	//! �h�c
	u32 Id;
	//! ���U���g�R�[�h
	u8 Result;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketMailAttachmentRecvResult()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketMailAttachmentRecvResult(u32 InId, u8 InResult)
	{
		Id = InId;
		Result = InResult;
		
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
		pStream->Serialize(&Result);
		
		return true;
	}
};

#endif		// #ifndef __PACKETMAILATTACHMENTRECVRESULT_H__
