/**
 * @file CachePacketSaveEquipRequest.h
 * @brief �����ۑ����N�G�X�g�p�P�b�g
 * @author NativePacketGenerator
 */

#ifndef __CACHEPACKETSAVEEQUIPREQUEST_H__
#define __CACHEPACKETSAVEEQUIPREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "CacheServerPacketID.h"


/**
 * @brief �����ۑ����N�G�X�g�p�P�b�g
 */
class CachePacketSaveEquipRequest  : public ProcessPacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return CachePacketID::CacheSaveEquipRequest; }

	

	//! �L�����N�^ID
	u32 CharacterId;
	//! �E�葕��
	u32 RightEquip;
	//! ���葕��
	u32 LeftEquip;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	CachePacketSaveEquipRequest()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	CachePacketSaveEquipRequest(u32 InClientId, u32 InCharacterId, u32 InRightEquip, u32 InLeftEquip)
	{
		ClientId = InClientId;
		CharacterId = InCharacterId;
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
		pStream->Serialize(&CharacterId);
		pStream->Serialize(&RightEquip);
		pStream->Serialize(&LeftEquip);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETSAVEEQUIPREQUEST_H__
