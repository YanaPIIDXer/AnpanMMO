/**
 * @file PacketSaveSkillListResponse.h
 * @brief �X�L�����X�g�ۑ����X�|���X�p�P�b�g
 * @author NativePacketGenerator
 */

#ifndef __PACKETSAVESKILLLISTRESPONSE_H__
#define __PACKETSAVESKILLLISTRESPONSE_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief �X�L�����X�g�ۑ����X�|���X�p�P�b�g
 */
class PacketSaveSkillListResponse  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::SaveSkillListResponse; }

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
	 * @return ����������true��Ԃ��B
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
