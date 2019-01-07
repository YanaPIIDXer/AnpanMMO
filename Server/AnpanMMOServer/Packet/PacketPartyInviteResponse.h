/**
 * @file PacketPartyInviteResponse.h
 * @brief �p�[�e�B���U���X�|���X�p�P�b�g
 * @author NativePacketGenerator
 */

#ifndef __PACKETPARTYINVITERESPONSE_H__
#define __PACKETPARTYINVITERESPONSE_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief �p�[�e�B���U���X�|���X�p�P�b�g
 */
class PacketPartyInviteResponse  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::PartyInviteResponse; }

	enum ResponseCode
	{
		//! 
		Accept,
		//! 
		Refuse,
	};

	//! 
	u32 CustomerId;
	//! 
	u8 Response;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketPartyInviteResponse()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketPartyInviteResponse(u32 InCustomerId, u8 InResponse)
	{
		CustomerId = InCustomerId;
		Response = InResponse;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief �V���A���C�Y
	 * @param[in] pStream �X�g���[��
	 * @return ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&CustomerId);
		pStream->Serialize(&Response);
		
		return true;
	}
};

#endif		// #ifndef __PACKETPARTYINVITERESPONSE_H__
