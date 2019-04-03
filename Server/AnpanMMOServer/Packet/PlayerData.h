/**
 * @file PlayerData.h
 * @brief �v���C���[�f�[�^�p�P�b�g
 * @author NativePacketGenerator
 */

#ifndef __PLAYERDATA_H__
#define __PLAYERDATA_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"


/**
 * @brief �v���C���[�f�[�^�p�P�b�g
 */
class PlayerData 
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	

	

	//! �t�t�h�c
	u32 Uuid;
	//! �w���W
	float X;
	//! �x���W
	float Y;
	//! �y���W
	float Z;
	//! ��]
	float Rotation;
	//! �g�o
	s32 Hp;
	//! �ő�g�o
	s32 MaxHp;
	//! ���O
	std::string Name;
	//! �W���u
	u8 Job;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PlayerData()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PlayerData(u32 InUuid, float InX, float InY, float InZ, float InRotation, s32 InHp, s32 InMaxHp, std::string InName, u8 InJob)
	{
		Uuid = InUuid;
		X = InX;
		Y = InY;
		Z = InZ;
		Rotation = InRotation;
		Hp = InHp;
		MaxHp = InMaxHp;
		Name = InName;
		Job = InJob;
		
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
		pStream->Serialize(&X);
		pStream->Serialize(&Y);
		pStream->Serialize(&Z);
		pStream->Serialize(&Rotation);
		pStream->Serialize(&Hp);
		pStream->Serialize(&MaxHp);
		pStream->Serialize(&Name);
		pStream->Serialize(&Job);
		
		return true;
	}
};

#endif		// #ifndef __PLAYERDATA_H__
