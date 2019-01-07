/**
 * @file PacketInstanceAreaTicketDiscard.h
 * @brief インスタンスマップチケット破棄パケット
 * @author NativePacketGenerator
 */

#ifndef __PACKETINSTANCEAREATICKETDISCARD_H__
#define __PACKETINSTANCEAREATICKETDISCARD_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief インスタンスマップチケット破棄パケット
 */
class PacketInstanceAreaTicketDiscard  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::InstanceAreaTicketDiscard; }

	

	

	/**
	 * @brief コンストラクタ
	 */
	PacketInstanceAreaTicketDiscard()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief シリアライズ
	 * @param[in] pStream ストリーム
	 * @return 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		
		return true;
	}
};

#endif		// #ifndef __PACKETINSTANCEAREATICKETDISCARD_H__
