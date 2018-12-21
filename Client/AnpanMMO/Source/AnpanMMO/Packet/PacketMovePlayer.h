/**
 * @file PacketMovePlayer.h
 * @brief �v���C���[�ړ�
 * @author NativePacketGenerator
 */

#ifndef __PACKETMOVEPLAYER_H__
#define __PACKETMOVEPLAYER_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief �v���C���[�ړ�
 */
class PacketMovePlayer  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::MovePlayer; }

	

	//! 
u32 Uuid;
	//! 
float X;
	//! 
float Y;
	//! 
float Z;
	//! 
float Rotation;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketMovePlayer()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketMovePlayer(u32 InUuid, float InX, float InY, float InZ, float InRotation)
	{
		Uuid = InUuid;
		X = InX;
		Y = InY;
		Z = InZ;
		Rotation = InRotation;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief �V���A���C�Y
	 * @param[in] pStream �X�g���[��
	 * @retrns ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Uuid);
		pStream->Serialize(&X);
		pStream->Serialize(&Y);
		pStream->Serialize(&Z);
		pStream->Serialize(&Rotation);
		
		return true;
	}
};

#endif		// #ifndef __PACKETMOVEPLAYER_H__
