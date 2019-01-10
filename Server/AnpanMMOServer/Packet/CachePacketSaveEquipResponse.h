/**
 * @file CachePacketSaveEquipResponse.h
 * @brief �����ۑ����X�|���X�p�P�b�g
 * @author NativePacketGenerator
 */

#ifndef __CACHEPACKETSAVEEQUIPRESPONSE_H__
#define __CACHEPACKETSAVEEQUIPRESPONSE_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "CacheServerPacketID.h"


/**
 * @brief �����ۑ����X�|���X�p�P�b�g
 */
class CachePacketSaveEquipResponse  : public ProcessPacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return CachePacketID::CacheSaveEquipResponse; }

	enum ResultCode
	{
		//! ����
		Success,
		//! �G���[
		Error,
	};

	//! ���U���g�R�[�h
	u8 Result;
	//! �E�葕��
	u32 RightEquip;
	//! ���葕��
	u32 LeftEquip;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	CachePacketSaveEquipResponse()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	CachePacketSaveEquipResponse(u32 InClientId, u8 InResult, u32 InRightEquip, u32 InLeftEquip)
	{
		ClientId = InClientId;
		Result = InResult;
		RightEquip = InRightEquip;
		LeftEquip = InLeftEquip;
		
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
		pStream->Serialize(&RightEquip);
		pStream->Serialize(&LeftEquip);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETSAVEEQUIPRESPONSE_H__
