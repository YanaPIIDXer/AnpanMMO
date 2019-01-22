/**
 * @file PacketExitShop.h
 * @brief �V���b�v�I���p�P�b�g
 * @author NativePacketGenerator
 */

#ifndef __PACKETEXITSHOP_H__
#define __PACKETEXITSHOP_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief �V���b�v�I���p�P�b�g
 */
class PacketExitShop  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::ExitShop; }

	

	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketExitShop()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief �V���A���C�Y
	 * @param[in] pStream �X�g���[��
	 * @return ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		
		return true;
	}
};

#endif		// #ifndef __PACKETEXITSHOP_H__
