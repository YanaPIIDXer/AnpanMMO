/**
 * @file PacketRemoveBuff.h
 * @brief �o�t�����p�P�b�g
 * @author NativePacketGenerator
 */

#ifndef __PACKETREMOVEBUFF_H__
#define __PACKETREMOVEBUFF_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief �o�t�����p�P�b�g
 */
class PacketRemoveBuff  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::RemoveBuff; }

	

	//! �o�t�^�C�v
	u8 BuffType;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketRemoveBuff()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketRemoveBuff(u8 InBuffType)
	{
		BuffType = InBuffType;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief �V���A���C�Y
	 * @param[in] pStream �X�g���[��
	 * @return ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&BuffType);
		
		return true;
	}
};

#endif		// #ifndef __PACKETREMOVEBUFF_H__
