/**
 * @file PacketPartyJoin.h
 * @brief �p�[�e�B�����p�P�b�g
 * @author NativePacketGenerator
 */

#ifndef __PACKETPARTYJOIN_H__
#define __PACKETPARTYJOIN_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PartyMemberData.h"
#include "FlexArray.h"
#include "PacketID.h"


/**
 * @brief �p�[�e�B�����p�P�b�g
 */
class PacketPartyJoin  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::PartyJoin; }

	

	//! UUID
	u32 Uuid;
	//! �����o���X�g
	FlexArray<PartyMemberData> MemberList;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketPartyJoin()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketPartyJoin(u32 InUuid, FlexArray<PartyMemberData> InMemberList)
	{
		Uuid = InUuid;
		MemberList = InMemberList;
		
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
		MemberList.Serialize(pStream);
		
		return true;
	}
};

#endif		// #ifndef __PACKETPARTYJOIN_H__
