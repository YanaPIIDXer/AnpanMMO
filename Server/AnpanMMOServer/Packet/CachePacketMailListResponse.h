/**
 * @file CachePacketMailListResponse.h
 * @brief ���[�����X�g���X�|���X�p�P�b�g
 * @author NativePacketGenerator
 */

#ifndef __CACHEPACKETMAILLISTRESPONSE_H__
#define __CACHEPACKETMAILLISTRESPONSE_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "FlexArray.h"
#include "MailData.h"
#include "CacheServerPacketID.h"


/**
 * @brief ���[�����X�g���X�|���X�p�P�b�g
 */
class CachePacketMailListResponse  : public ProcessPacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return CachePacketID::CacheMailListResponse; }

	

	//! ���[�����X�g
	FlexArray<MailData> List;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	CachePacketMailListResponse()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	CachePacketMailListResponse(u32 InClientId, FlexArray<MailData> InList)
	{
		ClientId = InClientId;
		List = InList;
		
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
		List.Serialize(pStream);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETMAILLISTRESPONSE_H__
