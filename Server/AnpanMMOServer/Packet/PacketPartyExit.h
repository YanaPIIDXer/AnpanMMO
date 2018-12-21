/**
 * @file PacketPartyExit.h
 * @brief パーティ離脱
 * @author NativePacketGenerator
 */

#ifndef __PACKETPARTYEXIT_H__
#define __PACKETPARTYEXIT_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief パーティ離脱
 */
class PacketPartyExit  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::PartyExit; }

	

	//! 
u32 Uuid;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketPartyExit()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketPartyExit(u32 InUuid)
	{
		Uuid = InUuid;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief �V���A���C�Y
	 * @param in pStream �X�g���[��
	 * @retrns ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Uuid);
		
		return true;
	}
};

#endif		// #ifndef __PACKETPARTYEXIT_H__
