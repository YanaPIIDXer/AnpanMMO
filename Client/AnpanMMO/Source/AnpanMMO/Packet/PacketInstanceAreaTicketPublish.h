/**
 * @file PacketInstanceAreaTicketPublish.h
 * @brief インスタンスマップチケット発行
 * @author NativePacketGenerator
 */

#ifndef __PACKETINSTANCEAREATICKETPUBLISH_H__
#define __PACKETINSTANCEAREATICKETPUBLISH_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief インスタンスマップチケット発行
 */
class PacketInstanceAreaTicketPublish  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::InstanceAreaTicketPublish; }

	

	//! 
u32 AreaId;
	//! 
u32 TicketId;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketInstanceAreaTicketPublish()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketInstanceAreaTicketPublish(u32 InAreaId, u32 InTicketId)
	{
		AreaId = InAreaId;
		TicketId = InTicketId;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief �V���A���C�Y
	 * @param in pStream �X�g���[��
	 * @retrns ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&AreaId);
		pStream->Serialize(&TicketId);
		
		return true;
	}
};

#endif		// #ifndef __PACKETINSTANCEAREATICKETPUBLISH_H__
