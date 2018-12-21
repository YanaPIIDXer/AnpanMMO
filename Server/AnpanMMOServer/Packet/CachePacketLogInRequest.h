/**
 * @file CachePacketLogInRequest.h
 * @brief ���O�C�����N�G�X�g
 * @author NativePacketGenerator
 */

#ifndef __CACHEPACKETLOGINREQUEST_H__
#define __CACHEPACKETLOGINREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "CacheServerPacketID.h"


/**
 * @brief ���O�C�����N�G�X�g
 */
class CachePacketLogInRequest  : public ProcessPacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return CachePacketID::CacheLogInRequest; }

	

	//! ���[�U�R�[�h
	std::string UserCode;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	CachePacketLogInRequest()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	CachePacketLogInRequest(u32 InClientId, std::string InUserCode)
	{
		ClientId = InClientId;
		UserCode = InUserCode;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief �V���A���C�Y
	 * @param[in] pStream �X�g���[��
	 * @retrn ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		ProcessPacketBase::Serialize(pStream);
		pStream->Serialize(&UserCode);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETLOGINREQUEST_H__
