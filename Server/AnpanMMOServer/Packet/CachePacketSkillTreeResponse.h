/**
 * @file CachePacketSkillTreeResponse.h
 * @brief �X�L���c���[���X�|���X�p�P�b�g
 * @author NativePacketGenerator
 */

#ifndef __CACHEPACKETSKILLTREERESPONSE_H__
#define __CACHEPACKETSKILLTREERESPONSE_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "CacheServerPacketID.h"


/**
 * @brief �X�L���c���[���X�|���X�p�P�b�g
 */
class CachePacketSkillTreeResponse  : public ProcessPacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return CachePacketID::CacheSkillTreeResponse; }

	enum ResultCode
	{
		//! ����
		Success,
		//! �G���[
		Error,
	};

	//! ����
	u8 Result;
	//! �J���Ă���m�[�h���X�g
	FlexArray<u32> OpenedList;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	CachePacketSkillTreeResponse()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	CachePacketSkillTreeResponse(u32 InClientId, u8 InResult, FlexArray<u32> InOpenedList)
	{
		ClientId = InClientId;
		Result = InResult;
		OpenedList = InOpenedList;
		
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
		pStream->Serialize(&Result);
		OpenedList.Serialize(pStream);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETSKILLTREERESPONSE_H__
