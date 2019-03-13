/**
 * @file PacketReceiveGMMessage.h
 * @brief �f�l���b�Z�[�W��M�p�P�b�g
 * @author NativePacketGenerator
 */

#ifndef __PACKETRECEIVEGMMESSAGE_H__
#define __PACKETRECEIVEGMMESSAGE_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief �f�l���b�Z�[�W��M�p�P�b�g
 */
class PacketReceiveGMMessage  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::ReceiveGMMessage; }

	

	//! ���b�Z�[�W
	std::string Message;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketReceiveGMMessage()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketReceiveGMMessage(std::string InMessage)
	{
		Message = InMessage;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief �V���A���C�Y
	 * @param[in] pStream �X�g���[��
	 * @return ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Message);
		
		return true;
	}
};

#endif		// #ifndef __PACKETRECEIVEGMMESSAGE_H__
