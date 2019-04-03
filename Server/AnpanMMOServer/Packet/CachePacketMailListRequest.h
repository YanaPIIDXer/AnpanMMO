/**
 * @file CachePacketMailListRequest.h
 * @brief ���[�����X�g���N�G�X�g�p�P�b�g
 * @author NativePacketGenerator
 */

#ifndef __CACHEPACKETMAILLISTREQUEST_H__
#define __CACHEPACKETMAILLISTREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "CacheServerPacketID.h"


/**
 * @brief ���[�����X�g���N�G�X�g�p�P�b�g
 */
class CachePacketMailListRequest  : public ProcessPacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return CachePacketID::CacheMailListRequest; }

	

	//! �J�X�^�}�h�c
	u32 CustomerId;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	CachePacketMailListRequest()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	CachePacketMailListRequest(u32 InClientId, u32 InCustomerId)
	{
		ClientId = InClientId;
		CustomerId = InCustomerId;
		
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
		pStream->Serialize(&CustomerId);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETMAILLISTREQUEST_H__
