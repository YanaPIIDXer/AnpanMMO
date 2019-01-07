/**
 * @file PacketInstanceAreaTicketPublish.h
 * @brief �C���X�^���X�}�b�v�`�P�b�g���s�p�P�b�g
 * @author NativePacketGenerator
 */

#ifndef __PACKETINSTANCEAREATICKETPUBLISH_H__
#define __PACKETINSTANCEAREATICKETPUBLISH_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief �C���X�^���X�}�b�v�`�P�b�g���s�p�P�b�g
 */
class PacketInstanceAreaTicketPublish  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::InstanceAreaTicketPublish; }

	

	//! �G���A�h�c
	u32 AreaId;
	//! �`�P�b�g�h�c
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
	 * @param[in] pStream �X�g���[��
	 * @return ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&AreaId);
		pStream->Serialize(&TicketId);
		
		return true;
	}
};

#endif		// #ifndef __PACKETINSTANCEAREATICKETPUBLISH_H__
