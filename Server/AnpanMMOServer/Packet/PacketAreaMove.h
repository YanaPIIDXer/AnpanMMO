/**
 * @file PacketAreaMove.h
 * @brief エリア移動
 * @author NativePacketGenerator
 */

#ifndef __PACKETAREAMOVE_H__
#define __PACKETAREAMOVE_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief エリア移動
 */
class PacketAreaMove  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::AreaMove; }

	

	//! 
u32 AreaId;
	//! 
float X;
	//! 
float Y;
	//! 
float Z;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketAreaMove()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketAreaMove(u32 InAreaId, float InX, float InY, float InZ)
	{
		AreaId = InAreaId;
		X = InX;
		Y = InY;
		Z = InZ;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief �V���A���C�Y
	 * @param in pStream �X�g���[��
	 * @retrns ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&AreaId);
		pStream->Serialize(&X);
		pStream->Serialize(&Y);
		pStream->Serialize(&Z);
		
		return true;
	}
};

#endif		// #ifndef __PACKETAREAMOVE_H__
