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
	 * @brief パケットＩＤ取得.
	 * @returns パケットＩＤ
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
	 * @brief コンストラクタ
	 */
	PacketSendChat()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketSendChat(u8 InType, std::string InMessage)
	{
		Type = InType;
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
		pStream->Serialize(&Type);
		pStream->Serialize(&Message);
		
		return true;
	}
};

#endif		// #ifndef __PACKETSENDCHAT_H__
