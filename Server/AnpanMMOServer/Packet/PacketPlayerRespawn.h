/**
 * @file PacketPlayerRespawn.h
 * @brief プレイヤーリスポン
 * @author NativePacketGenerator
 */

#ifndef __PACKETPLAYERRESPAWN_H__
#define __PACKETPLAYERRESPAWN_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief プレイヤーリスポン
 */
class PacketPlayerRespawn  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::PlayerRespawn; }

	

	//! 
u32 Uuid;
	//! 
float X;
	//! 
float Y;
	//! 
float Z;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketPlayerRespawn()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketPlayerRespawn(u32 InUuid, float InX, float InY, float InZ)
	{
		Uuid = InUuid;
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
		pStream->Serialize(&Uuid);
		pStream->Serialize(&X);
		pStream->Serialize(&Y);
		pStream->Serialize(&Z);
		
		return true;
	}
};

#endif		// #ifndef __PACKETPLAYERRESPAWN_H__
