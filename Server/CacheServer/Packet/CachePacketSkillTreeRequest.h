/**
 * @file CachePacketSkillTreeRequest.h
 * @brief �X�L���c���[���N�G�X�g
 * @author NativePacketGenerator
 */

#ifndef __CACHEPACKETSKILLTREEREQUEST_H__
#define __CACHEPACKETSKILLTREEREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "CacheServerPacketID.h"


/**
 * @brief �X�L���c���[���N�G�X�g
 */
class CachePacketSkillTreeRequest  : public ProcessPacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return CachePacketID::CacheSkillTreeRequest; }

	

	//! �L�����N�^�h�c
	u32 CharacterId;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	CachePacketSkillTreeRequest()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	CachePacketSkillTreeRequest(u32 InClientId, u32 InCharacterId)
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

#endif		// #ifndef __CACHEPACKETSKILLTREEREQUEST_H__
