/**
 * @file PacketPartyKick.h
 * @brief �p�[�e�B�����o�L�b�N
 * @author NativePacketGenerator
 */

#ifndef __PACKETPARTYKICK_H__
#define __PACKETPARTYKICK_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief �p�[�e�B�����o�L�b�N
 */
class PacketPartyKick  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::PartyKick; }

	

	//! UUID
	u32 Uuid;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketPartyKick()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketPartyKick(u32 InUuid)
	{
		Uuid = InUuid;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief �V���A���C�Y
	 * @param[in] pStream �X�g���[��
	 * @retrns ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Uuid);
		
		return true;
	}
};

#endif		// #ifndef __PACKETPARTYKICK_H__
