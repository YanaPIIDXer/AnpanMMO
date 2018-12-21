/**
 * @file CachePacketSkillListResponse.h
 * @brief スキルリストレスポンス
 * @author NativePacketGenerator
 */

#ifndef __CACHEPACKETSKILLLISTRESPONSE_H__
#define __CACHEPACKETSKILLLISTRESPONSE_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "CacheServerPacketID.h"


/**
 * @brief スキルリストレスポンス
 */
class CachePacketSkillListResponse  : public ProcessPacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return CachePacketID::CacheSkillListResponse; }

	enum ResultCode
	{
		//! 
		Success = 成功,
		//! 
		Error = エラー,
	};

	//! 
u8 Result;
	//! 
u32 NormalAttackId;
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
	CachePacketSkillListResponse()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	CachePacketSkillListResponse(u32 InClientId, u8 InResult, u32 InNormalAttackId, u32 InSkillId1, u32 InSkillId2, u32 InSkillId3, u32 InSkillId4)
	{
		ClientId = InClientId;
		Result = InResult;
		NormalAttackId = InNormalAttackId;
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
		pStream->Serialize(&Result);
		pStream->Serialize(&NormalAttackId);
		pStream->Serialize(&SkillId1);
		pStream->Serialize(&SkillId2);
		pStream->Serialize(&SkillId3);
		pStream->Serialize(&SkillId4);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETSKILLLISTRESPONSE_H__
