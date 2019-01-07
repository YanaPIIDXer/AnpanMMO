/**
 * @file PacketPartyInviteResult.h
 * @brief �p�[�e�B���U���ʃp�P�b�g
 * @author NativePacketGenerator
 */

#ifndef __PACKETPARTYINVITERESULT_H__
#define __PACKETPARTYINVITERESULT_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief �p�[�e�B���U���ʃp�P�b�g
 */
class PacketPartyInviteResult  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::PartyInviteResult; }

	enum ResultCode
	{
		//! 
		Success,
		//! 
		AlreadyJoinOtherParty,
		//! 
		Error,
	};

	//! 
	u8 Result;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketPartyInviteResult()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketPartyInviteResult(u8 InResult)
	{
		Result = InResult;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief �V���A���C�Y
	 * @param[in] pStream �X�g���[��
	 * @return ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Result);
		
		return true;
	}
};

#endif		// #ifndef __PACKETPARTYINVITERESULT_H__
