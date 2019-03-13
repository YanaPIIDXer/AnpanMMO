/**
 * @file PacketReceiveGMMessage.h
 * @brief ＧＭメッセージ受信パケット
 * @author NativePacketGenerator
 */

#ifndef __PACKETRECEIVEGMMESSAGE_H__
#define __PACKETRECEIVEGMMESSAGE_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief ＧＭメッセージ受信パケット
 */
class PacketReceiveGMMessage  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::ReceiveGMMessage; }

	

	//! メッセージ
	std::string Message;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketReceiveGMMessage()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketReceiveGMMessage(std::string InMessage)
	{
		Message = InMessage;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief シリアライズ
	 * @param[in] pStream ストリーム
	 * @return 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Message);
		
		return true;
	}
};

#endif		// #ifndef __PACKETRECEIVEGMMESSAGE_H__
