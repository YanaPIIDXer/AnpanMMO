/**
 * @file CachePacketCreateCharacterRequest.h
 * @brief �L�����N�^�쐬���N�G�X�g
 * @author NativePacketGenerator
 */

#ifndef __CACHEPACKETCREATECHARACTERREQUEST_H__
#define __CACHEPACKETCREATECHARACTERREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "CacheServerPacketID.h"


/**
 * @brief �L�����N�^�쐬���N�G�X�g
 */
class CachePacketCreateCharacterRequest  : public ProcessPacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return CachePacketID::CacheCreateCharacterRequest; }

	

	//! �J�X�^�}ID
	u32 CustomerId;
	//! �L�����N�^��
	std::string CharacterName;
	//! �W���u
	u8 Job;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	CachePacketCreateCharacterRequest()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	CachePacketCreateCharacterRequest(u32 InClientId, u32 InCustomerId, std::string InCharacterName, u8 InJob)
	{
		ClientId = InClientId;
		CustomerId = InCustomerId;
		CharacterName = InCharacterName;
		Job = InJob;
		
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
		pStream->Serialize(&CustomerId);
		pStream->Serialize(&CharacterName);
		pStream->Serialize(&Job);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETCREATECHARACTERREQUEST_H__
