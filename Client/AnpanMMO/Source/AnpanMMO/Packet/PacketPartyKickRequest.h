/**
 * @file PacketPartyKickRequest.h
 * @brief �p�[�e�B�����o�L�b�N���N�G�X�g�p�P�b�g
 * @author NativePacketGenerator
 */

#ifndef __PACKETPARTYKICKREQUEST_H__
#define __PACKETPARTYKICKREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief �p�[�e�B�����o�L�b�N���N�G�X�g�p�P�b�g
 */
class PacketPartyKickRequest  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::PartyKickRequest; }

	

	//! UUID
	u32 Uuid;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketPartyKickRequest()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketPartyKickRequest(u32 InUuid)
	{
		Uuid = InUuid;
		
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
		
		return true;
	}
};

#endif		// #ifndef __PACKETPARTYKICKREQUEST_H__
