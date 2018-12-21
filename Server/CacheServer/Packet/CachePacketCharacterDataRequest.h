/**
 * @file CachePacketCharacterDataRequest.h
 * @brief キャラクタ情報リクエスト
 * @author NativePacketGenerator
 */

#ifndef __CACHEPACKETCHARACTERDATAREQUEST_H__
#define __CACHEPACKETCHARACTERDATAREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "CacheServerPacketID.h"


/**
 * @brief キャラクタ情報リクエスト
 */
class CachePacketCharacterDataRequest  : public ProcessPacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return CachePacketID::CacheCharacterDataRequest; }

	

	//! 
u32 CustomerId;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	CachePacketCharacterDataRequest()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	CachePacketCharacterDataRequest(u32 InClientId, u32 InCustomerId)
	{
		ClientId = InClientId;
		CustomerId = InCustomerId;
		
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
		pStream->Serialize(&CustomerId);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETCHARACTERDATAREQUEST_H__
