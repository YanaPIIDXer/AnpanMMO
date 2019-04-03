/**
 * @file CachePacketMailAttachmentRecvRequest.h
 * @brief ���[���Y�t����M�v���p�P�b�g
 * @author NativePacketGenerator
 */

#ifndef __CACHEPACKETMAILATTACHMENTRECVREQUEST_H__
#define __CACHEPACKETMAILATTACHMENTRECVREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "CacheServerPacketID.h"


/**
 * @brief ���[���Y�t����M�v���p�P�b�g
 */
class CachePacketMailAttachmentRecvRequest  : public ProcessPacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return CachePacketID::CacheMailAttachmentRecvRequest; }

	

	//! �h�c
	u32 Id;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	CachePacketMailAttachmentRecvRequest()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	CachePacketMailAttachmentRecvRequest(u32 InClientId, u32 InId)
	{
		ClientId = InClientId;
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
		ProcessPacketBase::Serialize(pStream);
		pStream->Serialize(&Id);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETMAILATTACHMENTRECVREQUEST_H__
