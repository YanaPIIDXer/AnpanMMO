/**
 * @file PacketSendChat.h
 * @brief チャット送信
 * @author NativePacketGenerator
 */

#ifndef __PACKETSENDCHAT_H__
#define __PACKETSENDCHAT_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief チャット送信
 */
class PacketSendChat  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::SendChat; }

	enum ChatType
	{
		//! 
		Say = Say,
		//! 
		Shout = Shout,
	};

	//! 
u8 Type;
	//! 
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
	 * @param in pStream �X�g���[��
	 * @retrns ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Type);
		pStream->Serialize(&Message);
		
		return true;
	}
};

#endif		// #ifndef __PACKETSENDCHAT_H__
