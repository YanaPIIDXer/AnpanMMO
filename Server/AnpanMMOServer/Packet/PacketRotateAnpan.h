/**
 * @file PacketRotateAnpan.h
 * @brief アンパン回転
 * @author NativePacketGenerator
 */

#ifndef __PACKETROTATEANPAN_H__
#define __PACKETROTATEANPAN_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief アンパン回転
 */
class PacketRotateAnpan  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::RotateAnpan; }

	

	//! 
u32 Uuid;
	//! 
float Rotation;
	//! 
s32 RotateMilliSec;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketRotateAnpan()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketRotateAnpan(u32 InUuid, float InRotation, s32 InRotateMilliSec)
	{
		Uuid = InUuid;
		Rotation = InRotation;
		RotateMilliSec = InRotateMilliSec;
		
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
		pStream->Serialize(&Rotation);
		pStream->Serialize(&RotateMilliSec);
		
		return true;
	}
};

#endif		// #ifndef __PACKETROTATEANPAN_H__
