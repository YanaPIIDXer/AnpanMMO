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
	 * @brief パケットＩＤ取得.
	 * @returns パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::ReceiveChat; }

	

	//! 
u32 Uuid;
	//! 
std::string Name;
	//! 
std::string Message;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketReceiveChat()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketReceiveChat(u32 InUuid, std::string InName, std::string InMessage)
	{
		Uuid = InUuid;
		Name = InName;
		Message = InMessage;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief シリアライズ
	 * @param[in] pStream ストリーム
	 * @retrns 成功したらtrueを返す。
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
