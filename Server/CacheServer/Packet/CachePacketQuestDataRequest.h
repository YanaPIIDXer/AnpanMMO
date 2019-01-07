/**
 * @file CachePacketQuestDataRequest.h
 * @brief �N�G�X�g�f�[�^���N�G�X�g�p�P�b�g
 * @author NativePacketGenerator
 */

#ifndef __CACHEPACKETQUESTDATAREQUEST_H__
#define __CACHEPACKETQUESTDATAREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "CacheServerPacketID.h"


/**
 * @brief �N�G�X�g�f�[�^���N�G�X�g�p�P�b�g
 */
class CachePacketQuestDataRequest  : public ProcessPacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return CachePacketID::CacheQuestDataRequest; }

	

	//! �L�����N�^�h�c
	u32 CharacterId;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	CachePacketQuestDataRequest()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	CachePacketQuestDataRequest(u32 InClientId, u32 InCharacterId)
	{
		ClientId = InClientId;
		CharacterId = InCharacterId;
		
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
		pStream->Serialize(&CharacterId);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETQUESTDATAREQUEST_H__
