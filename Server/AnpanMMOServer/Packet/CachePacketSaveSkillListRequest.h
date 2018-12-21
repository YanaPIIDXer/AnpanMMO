/**
 * @file CachePacketSaveSkillListRequest.h
 * @brief スキルリスト保存リクエスト
 * @author NativePacketGenerator
 */

#ifndef __CACHEPACKETSAVESKILLLISTREQUEST_H__
#define __CACHEPACKETSAVESKILLLISTREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "CacheServerPacketID.h"


/**
 * @brief スキルリスト保存リクエスト
 */
class CachePacketSaveSkillListRequest  : public ProcessPacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return CachePacketID::CacheSaveSkillListRequest; }

	

	//! 
u32 CharacterId;
	//! 
u32 SkillId1;
	//! 
u32 SkillId2;
	//! 
u32 SkillId3;
	//! 
u32 SkillId4;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	CachePacketSaveSkillListRequest()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	CachePacketSaveSkillListRequest(u32 InClientId, u32 InCharacterId, u32 InSkillId1, u32 InSkillId2, u32 InSkillId3, u32 InSkillId4)
	{
		ClientId = InClientId;
		CharacterId = InCharacterId;
		SkillId1 = InSkillId1;
		SkillId2 = InSkillId2;
		SkillId3 = InSkillId3;
		SkillId4 = InSkillId4;
		
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
		pStream->Serialize(&SkillId1);
		pStream->Serialize(&SkillId2);
		pStream->Serialize(&SkillId3);
		pStream->Serialize(&SkillId4);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETSAVESKILLLISTREQUEST_H__
