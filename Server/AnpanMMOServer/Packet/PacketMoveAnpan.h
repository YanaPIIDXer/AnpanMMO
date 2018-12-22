/**
 * @file PacketMoveAnpan.h
 * @brief �A���p���ړ�
 * @author NativePacketGenerator
 */

#ifndef __PACKETMOVEANPAN_H__
#define __PACKETMOVEANPAN_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief �A���p���ړ�
 */
class PacketMoveAnpan  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::MoveAnpan; }

	

	//! UUID
	u32 Uuid;
	//! X���W
	float X;
	//! Y���W
	float Y;
	//! Z���W
	float Z;
	//! �ړ����ԁi�~���b�j
	s32 MoveMilliSec;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketMoveAnpan()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketMoveAnpan(u32 InUuid, float InX, float InY, float InZ, s32 InMoveMilliSec)
	{
		Uuid = InUuid;
		X = InX;
		Y = InY;
		Z = InZ;
		MoveMilliSec = InMoveMilliSec;
		
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
		pStream->Serialize(&MoveMilliSec);
		
		return true;
	}
};

#endif		// #ifndef __PACKETMOVEANPAN_H__
