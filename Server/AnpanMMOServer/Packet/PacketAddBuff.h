/**
 * @file PacketAddBuff.h
 * @brief �o�t�ǉ��p�P�b�g
 * @author NativePacketGenerator
 */

#ifndef __PACKETADDBUFF_H__
#define __PACKETADDBUFF_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief �o�t�ǉ��p�P�b�g
 */
class PacketAddBuff  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::AddBuff; }

	

	//! �o�t�h�c
	u32 BuffId;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketAddBuff()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketAddBuff(u32 InBuffId)
	{
		BuffId = InBuffId;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief �V���A���C�Y
	 * @param[in] pStream �X�g���[��
	 * @return ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&BuffId);
		
		return true;
	}
};

#endif		// #ifndef __PACKETADDBUFF_H__
