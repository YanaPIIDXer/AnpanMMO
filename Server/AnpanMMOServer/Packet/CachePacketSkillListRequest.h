/**
 * @file CachePacketSkillListRequest.h
 * @brief �X�L�����X�g���N�G�X�g�p�P�b�g
 * @author NativePacketGenerator
 */

#ifndef __CACHEPACKETSKILLLISTREQUEST_H__
#define __CACHEPACKETSKILLLISTREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "CacheServerPacketID.h"


/**
 * @brief �X�L�����X�g���N�G�X�g�p�P�b�g
 */
class CachePacketSkillListRequest  : public ProcessPacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return CachePacketID::CacheSkillListRequest; }

	

	//! �L�����N�^�h�c
	u32 CharacterId;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	CachePacketSkillListRequest()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	CachePacketSkillListRequest(u32 InClientId, u32 InCharacterId)
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

#endif		// #ifndef __CACHEPACKETSKILLLISTREQUEST_H__
