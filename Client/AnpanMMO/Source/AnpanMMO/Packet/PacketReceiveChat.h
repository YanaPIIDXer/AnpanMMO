/**
 * @file PacketReceiveChat.h
 * @brief チャット受信
 * @author NativePacketGenerator
 */

#ifndef __PACKETRECEIVECHAT_H__
#define __PACKETRECEIVECHAT_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief チャット受信
 */
class PacketReceiveChat  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::ReceiveChat; }

	

	//! 
u32 Uuid;
	//! 
std::string Name;
	//! 
std::string Message;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketReceiveChat()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketReceiveChat(u32 InUuid, std::string InName, std::string InMessage)
	{
		Uuid = InUuid;
		Name = InName;
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
		pStream->Serialize(&Uuid);
		pStream->Serialize(&Name);
		pStream->Serialize(&Message);
		
		return true;
	}
};

#endif		// #ifndef __PACKETRECEIVECHAT_H__
