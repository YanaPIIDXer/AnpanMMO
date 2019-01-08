/**
 * @file CachePacketCharacterDataSave.h
 * @brief �L�����N�^�ۑ����N�G�X�g�p�P�b�g
 * @author NativePacketGenerator
 */

#ifndef __CACHEPACKETCHARACTERDATASAVE_H__
#define __CACHEPACKETCHARACTERDATASAVE_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "CacheServerPacketID.h"


/**
 * @brief �L�����N�^�ۑ����N�G�X�g�p�P�b�g
 */
class CachePacketCharacterDataSave  : public ProcessPacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return CachePacketID::CacheCharacterDataSave; }

	

	//! �L�����N�^�h�c
	u32 CharacterId;
	//! ���x��
	u32 Level;
	//! �o���l
	s32 Exp;
	//! �ŏI���O�A�E�g�G���A�h�c
	u32 LastAreaId;
	//! �ŏI���O�A�E�g�w���W
	float LastX;
	//! �ŏI���O�A�E�g�x���W
	float LastY;
	//! �ŏI���O�A�E�g�y���W
	float LastZ;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	CachePacketCharacterDataSave()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	CachePacketCharacterDataSave(u32 InClientId, u32 InCharacterId, u32 InLevel, s32 InExp, u32 InLastAreaId, float InLastX, float InLastY, float InLastZ)
	{
		ClientId = InClientId;
		CharacterId = InCharacterId;
		Level = InLevel;
		Exp = InExp;
		LastAreaId = InLastAreaId;
		LastX = InLastX;
		LastY = InLastY;
		LastZ = InLastZ;
		
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
		pStream->Serialize(&Level);
		pStream->Serialize(&Exp);
		pStream->Serialize(&LastAreaId);
		pStream->Serialize(&LastX);
		pStream->Serialize(&LastY);
		pStream->Serialize(&LastZ);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETCHARACTERDATASAVE_H__
