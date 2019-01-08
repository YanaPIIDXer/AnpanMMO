/**
 * @file PacketInstanceAreaTicketPublish.h
 * @brief インスタンスマップチケット発行パケット
 * @author NativePacketGenerator
 */

#ifndef __PACKETINSTANCEAREATICKETPUBLISH_H__
#define __PACKETINSTANCEAREATICKETPUBLISH_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief インスタンスマップチケット発行パケット
 */
class PacketInstanceAreaTicketPublish  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::InstanceAreaTicketPublish; }

	

	//! エリアＩＤ
	u32 AreaId;
	//! チケットＩＤ
	u32 TicketId;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketInstanceAreaTicketPublish()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketInstanceAreaTicketPublish(u32 InAreaId, u32 InTicketId)
	{
		AreaId = InAreaId;
		TicketId = InTicketId;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief シリアライズ
	 * @param[in] pStream ストリーム
	 * @return 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&AreaId);
		pStream->Serialize(&TicketId);
		
		return true;
	}
};

#endif		// #ifndef __PACKETINSTANCEAREATICKETPUBLISH_H__
