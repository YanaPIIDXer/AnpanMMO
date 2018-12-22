/**
 * @file PacketPartyExitRequest.h
 * @brief �p�[�e�B���E���N�G�X�g
 * @author NativePacketGenerator
 */

#ifndef __PACKETPARTYEXITREQUEST_H__
#define __PACKETPARTYEXITREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief �p�[�e�B���E���N�G�X�g
 */
class PacketPartyExitRequest  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::PartyExitRequest; }

	

	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketPartyExitRequest()
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

#endif		// #ifndef __PACKETPARTYEXITREQUEST_H__
