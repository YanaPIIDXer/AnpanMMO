/**
 * @file CachePacketLogInRequest.h
 * @brief ログインリクエスト
 * @author NativePacketGenerator
 */

#ifndef __CACHEPACKETLOGINREQUEST_H__
#define __CACHEPACKETLOGINREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "CacheServerPacketID.h"


/**
 * @brief ログインリクエスト
 */
class CachePacketLogInRequest  : public ProcessPacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return CachePacketID::CacheLogInRequest; }

	

	//! 
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
	 * @param in pStream �X�g���[��
	 * @retrns ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		ProcessPacketBase::Serialize(pStream);
		pStream->Serialize(&UserCode);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETLOGINREQUEST_H__
