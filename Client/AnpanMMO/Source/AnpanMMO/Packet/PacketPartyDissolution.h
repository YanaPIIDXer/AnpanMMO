/**
 * @file PacketPartyDissolution.h
 * @brief �p�[�e�B���U
 * @author NativePacketGenerator
 */

#ifndef __PACKETPARTYDISSOLUTION_H__
#define __PACKETPARTYDISSOLUTION_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief �p�[�e�B���U
 */
class PacketPartyDissolution  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::PartyDissolution; }

	

	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketPartyDissolution()
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

#endif		// #ifndef __PACKETPARTYDISSOLUTION_H__
