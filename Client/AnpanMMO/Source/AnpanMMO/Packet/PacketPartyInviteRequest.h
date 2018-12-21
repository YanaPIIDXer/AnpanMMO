/**
 * @file PacketPartyInviteRequest.h
 * @brief パーティ勧誘リクエスト
 * @author NativePacketGenerator
 */

#ifndef __PACKETPARTYINVITEREQUEST_H__
#define __PACKETPARTYINVITEREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief パーティ勧誘リクエスト
 */
class PacketPartyInviteRequest  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::PartyInviteRequest; }

	

	//! 
u32 TargetUuid;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketPartyInviteRequest()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketPartyInviteRequest(u32 InTargetUuid)
	{
		TargetUuid = InTargetUuid;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief �V���A���C�Y
	 * @param in pStream �X�g���[��
	 * @retrns ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&TargetUuid);
		
		return true;
	}
};

#endif		// #ifndef __PACKETPARTYINVITEREQUEST_H__
