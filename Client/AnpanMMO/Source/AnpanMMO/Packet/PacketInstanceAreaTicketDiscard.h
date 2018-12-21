/**
 * @file PacketInstanceAreaTicketDiscard.h
 * @brief インスタンスマップチケット破棄
 * @author NativePacketGenerator
 */

#ifndef __PACKETINSTANCEAREATICKETDISCARD_H__
#define __PACKETINSTANCEAREATICKETDISCARD_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief インスタンスマップチケット破棄
 */
class PacketInstanceAreaTicketDiscard  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::InstanceAreaTicketDiscard; }

	

	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketInstanceAreaTicketDiscard()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief �V���A���C�Y
	 * @param in pStream �X�g���[��
	 * @retrns ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		
		return true;
	}
};

#endif		// #ifndef __PACKETINSTANCEAREATICKETDISCARD_H__
