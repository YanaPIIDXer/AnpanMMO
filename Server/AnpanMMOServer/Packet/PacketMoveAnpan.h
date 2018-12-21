/**
 * @file PacketMoveAnpan.h
 * @brief アンパン移動
 * @author NativePacketGenerator
 */

#ifndef __PACKETMOVEANPAN_H__
#define __PACKETMOVEANPAN_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief アンパン移動
 */
class PacketMoveAnpan  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::MoveAnpan; }

	

	//! 
u32 Uuid;
	//! 
float X;
	//! 
float Y;
	//! 
float Z;
	//! 
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
	 * @param in pStream �X�g���[��
	 * @retrns ����������true��Ԃ��B
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
