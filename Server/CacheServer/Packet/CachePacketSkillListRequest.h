/**
 * @file CachePacketSkillListRequest.h
 * @brief スキルリストリクエスト
 * @author NativePacketGenerator
 */

#ifndef __CACHEPACKETSKILLLISTREQUEST_H__
#define __CACHEPACKETSKILLLISTREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "CacheServerPacketID.h"


/**
 * @brief スキルリストリクエスト
 */
class CachePacketSkillListRequest  : public ProcessPacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return CachePacketID::CacheSkillListRequest; }

	

	//! 
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
	 * @param in pStream �X�g���[��
	 * @retrns ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		ProcessPacketBase::Serialize(pStream);
		pStream->Serialize(&CharacterId);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETSKILLLISTREQUEST_H__
