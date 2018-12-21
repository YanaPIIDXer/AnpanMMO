/**
 * @file CachePacketSaveSkillListResponse.h
 * @brief �X�L�����X�g�ۑ����X�|���X
 * @author NativePacketGenerator
 */

#ifndef __CACHEPACKETSAVESKILLLISTRESPONSE_H__
#define __CACHEPACKETSAVESKILLLISTRESPONSE_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "CacheServerPacketID.h"


/**
 * @brief �X�L�����X�g�ۑ����X�|���X
 */
class CachePacketSaveSkillListResponse  : public ProcessPacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return CachePacketID::CacheSaveSkillListResponse; }

	enum ResultCode
	{
		//! ����
		Success,
		//! �G���[
		Error,
	};

	//! ����
	u8 Result;
	//! �X�L���h�c�P
	u32 SkillId1;
	//! �X�L���h�c�Q
	u32 SkillId2;
	//! �X�L���h�c�R
	u32 SkillId3;
	//! �X�L���h�c�S
	u32 SkillId4;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	CachePacketSaveSkillListResponse()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	CachePacketSaveSkillListResponse(u32 InClientId, u8 InResult, u32 InSkillId1, u32 InSkillId2, u32 InSkillId3, u32 InSkillId4)
	{
		ClientId = InClientId;
		Result = InResult;
		SkillId1 = InSkillId1;
		SkillId2 = InSkillId2;
		SkillId3 = InSkillId3;
		SkillId4 = InSkillId4;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief �V���A���C�Y
	 * @param[in] pStream �X�g���[��
	 * @retrns ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		ProcessPacketBase::Serialize(pStream);
		pStream->Serialize(&Result);
		pStream->Serialize(&SkillId1);
		pStream->Serialize(&SkillId2);
		pStream->Serialize(&SkillId3);
		pStream->Serialize(&SkillId4);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETSAVESKILLLISTRESPONSE_H__
