/**
 * @file PacketSaveSkillListResponse.h
 * @brief �X�L�����X�g�ۑ����X�|���X
 * @author NativePacketGenerator
 */

#ifndef __PACKETSAVESKILLLISTRESPONSE_H__
#define __PACKETSAVESKILLLISTRESPONSE_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief �X�L�����X�g�ۑ����X�|���X
 */
class PacketSaveSkillListResponse  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::SaveSkillListResponse; }

	enum ResultCode
	{
		//! 
		Success = ����,
		//! 
		Error = �G���[,
	};

	//! 
u8 Result;
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
	PacketSaveSkillListResponse()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketSaveSkillListResponse(u8 InResult, u32 InSkillId1, u32 InSkillId2, u32 InSkillId3, u32 InSkillId4)
	{
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
		pStream->Serialize(&Result);
		pStream->Serialize(&SkillId1);
		pStream->Serialize(&SkillId2);
		pStream->Serialize(&SkillId3);
		pStream->Serialize(&SkillId4);
		
		return true;
	}
};

#endif		// #ifndef __PACKETSAVESKILLLISTRESPONSE_H__
