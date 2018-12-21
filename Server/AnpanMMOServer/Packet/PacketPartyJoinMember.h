/**
 * @file PacketPartyJoinMember.h
 * @brief パーティメンバ加入
 * @author NativePacketGenerator
 */

#ifndef __PACKETPARTYJOINMEMBER_H__
#define __PACKETPARTYJOINMEMBER_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PartyMemberData.h"
#include "PacketID.h"


/**
 * @brief パーティメンバ加入
 */
class PacketPartyJoinMember  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::PartyJoinMember; }

	

	//! 
PartyMemberData MemberData;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketPartyJoinMember()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketPartyJoinMember(PartyMemberData InMemberData)
	{
		MemberData = InMemberData;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief �V���A���C�Y
	 * @param in pStream �X�g���[��
	 * @retrns ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		MemberData.Serialize(pStream);
		
		return true;
	}
};

#endif		// #ifndef __PACKETPARTYJOINMEMBER_H__
