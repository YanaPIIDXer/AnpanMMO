/**
 * @file PacketInstanceAreaTicketDiscard.h
 * @brief �C���X�^���X�}�b�v�`�P�b�g�j���p�P�b�g
 * @author NativePacketGenerator
 */

#ifndef __PACKETINSTANCEAREATICKETDISCARD_H__
#define __PACKETINSTANCEAREATICKETDISCARD_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief �C���X�^���X�}�b�v�`�P�b�g�j���p�P�b�g
 */
class PacketInstanceAreaTicketDiscard  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
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
	 * @param[in] pStream �X�g���[��
	 * @return ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		
		return true;
	}
};

#endif		// #ifndef __PACKETINSTANCEAREATICKETDISCARD_H__
