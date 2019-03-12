/**
 * @file CachePacketCharacterDataResult.h
 * @brief �L�����N�^��񃌃X�|���X�p�P�b�g
 * @author NativePacketGenerator
 */

#ifndef __CACHEPACKETCHARACTERDATARESULT_H__
#define __CACHEPACKETCHARACTERDATARESULT_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "CacheServerPacketID.h"


/**
 * @brief �L�����N�^��񃌃X�|���X�p�P�b�g
 */
class CachePacketCharacterDataResult  : public ProcessPacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return CachePacketID::CacheCharacterDataResult; }

	enum ResultCode
	{
		//! ����
		Success,
		//! �G���[
		Error,
	};

	//! �L�����N�^�h�c
	u32 CharacterId;
	//! ����
	u8 Result;
	//! ���O
	std::string Name;
	//! �W���u
	u8 Job;
	//! ���x��
	u32 Level;
	//! �o���l
	s32 Exp;
	//! �S�[���h
	u32 Gold;
	//! �E�葕��
	u32 RightEquip;
	//! ���葕��
	u32 LeftEquip;
	//! �f�l���H
	u8 IsGM;
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
	CachePacketCharacterDataResult()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	CachePacketCharacterDataResult(u32 InClientId, u32 InCharacterId, u8 InResult, std::string InName, u8 InJob, u32 InLevel, s32 InExp, u32 InGold, u32 InRightEquip, u32 InLeftEquip, u8 InIsGM, u32 InLastAreaId, float InLastX, float InLastY, float InLastZ)
	{
		ClientId = InClientId;
		CharacterId = InCharacterId;
		Result = InResult;
		Name = InName;
		Job = InJob;
		Level = InLevel;
		Exp = InExp;
		Gold = InGold;
		RightEquip = InRightEquip;
		LeftEquip = InLeftEquip;
		IsGM = InIsGM;
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
		pStream->Serialize(&Result);
		pStream->Serialize(&Name);
		pStream->Serialize(&Job);
		pStream->Serialize(&Level);
		pStream->Serialize(&Exp);
		pStream->Serialize(&Gold);
		pStream->Serialize(&RightEquip);
		pStream->Serialize(&LeftEquip);
		pStream->Serialize(&IsGM);
		pStream->Serialize(&LastAreaId);
		pStream->Serialize(&LastX);
		pStream->Serialize(&LastY);
		pStream->Serialize(&LastZ);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETCHARACTERDATARESULT_H__
