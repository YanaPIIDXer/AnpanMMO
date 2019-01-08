/**
 * @file PacketSendChat.h
 * @brief �`���b�g���M�p�P�b�g
 * @author NativePacketGenerator
 */

#ifndef __PACKETSENDCHAT_H__
#define __PACKETSENDCHAT_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief �`���b�g���M�p�P�b�g
 */
class PacketSendChat  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::SendChat; }

	enum ChatType
	{
		//! Say
		Say,
		//! Shout
		Shout,
	};

	//! �^�C�v
	u8 Type;
	//! ���b�Z�[�W
	std::string Message;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketSendChat()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketSendChat(u8 InType, std::string InMessage)
	{
		Type = InType;
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
		pStream->Serialize(&Type);
		pStream->Serialize(&Message);
		
		return true;
	}
};

#endif		// #ifndef __PACKETSENDCHAT_H__
