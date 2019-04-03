/**
 * @file AnpanData.h
 * @brief �A���p���f�[�^�p�P�b�g
 * @author NativePacketGenerator
 */

#ifndef __ANPANDATA_H__
#define __ANPANDATA_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"


/**
 * @brief �A���p���f�[�^�p�P�b�g
 */
class AnpanData 
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	

	

	//! UUID
	u32 Uuid;
	//! �}�X�^�h�c
	u32 MasterId;
	//! X���W
	float X;
	//! Y���W
	float Y;
	//! Z���W
	float Z;
	//! ��]
	float Rotation;
	//! HP
	s32 Hp;
	//! �ő�HP
	s32 MaxHp;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	AnpanData()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	AnpanData(u32 InUuid, u32 InMasterId, float InX, float InY, float InZ, float InRotation, s32 InHp, s32 InMaxHp)
	{
		Uuid = InUuid;
		MasterId = InMasterId;
		X = InX;
		Y = InY;
		Z = InZ;
		Rotation = InRotation;
		Hp = InHp;
		MaxHp = InMaxHp;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief �V���A���C�Y
	 * @param[in] pStream �X�g���[��
	 * @return ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Uuid);
		pStream->Serialize(&MasterId);
		pStream->Serialize(&X);
		pStream->Serialize(&Y);
		pStream->Serialize(&Z);
		pStream->Serialize(&Rotation);
		pStream->Serialize(&Hp);
		pStream->Serialize(&MaxHp);
		
		return true;
	}
};

#endif		// #ifndef __ANPANDATA_H__
