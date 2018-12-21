/**
 * @file PacketTime.h
 * @brief ���O�C�����̎��Ԓʒm
 * @author NativePacketGenerator
 */

#ifndef __PACKETTIME_H__
#define __PACKETTIME_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief ���O�C�����̎��Ԓʒm
 */
class PacketTime  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::Time; }

	

	//! �}�X�^�h�c
	u32 MasterId;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketTime()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketTime(u32 InMasterId)
	{
		MasterId = InMasterId;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief �V���A���C�Y
	 * @param[in] pStream �X�g���[��
	 * @retrns ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&MasterId);
		
		return true;
	}
};

#endif		// #ifndef __PACKETTIME_H__
