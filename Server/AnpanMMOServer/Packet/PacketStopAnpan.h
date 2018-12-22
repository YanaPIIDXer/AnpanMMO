/**
 * @file PacketStopAnpan.h
 * @brief �A���p����~
 * @author NativePacketGenerator
 */

#ifndef __PACKETSTOPANPAN_H__
#define __PACKETSTOPANPAN_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief �A���p����~
 */
class PacketStopAnpan  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::StopAnpan; }

	

	//! UUID
	u32 Uuid;
	//! X���W
	float X;
	//! Y���W
	float Y;
	//! Z���W
	float Z;
	//! ��]
	float Rotation;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketStopAnpan()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketStopAnpan(u32 InUuid, float InX, float InY, float InZ, float InRotation)
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
	 * @return ����������true��Ԃ��B
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

#endif		// #ifndef __PACKETSTOPANPAN_H__
