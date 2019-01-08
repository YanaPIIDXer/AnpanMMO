/**
 * @file PacketPartyKickRequest.h
 * @brief パーティメンバキックリクエストパケット
 * @author NativePacketGenerator
 */

#ifndef __PACKETPARTYKICKREQUEST_H__
#define __PACKETPARTYKICKREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief パーティメンバキックリクエストパケット
 */
class PacketPartyKickRequest  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::PartyKickRequest; }

	

	//! UUID
	u32 Uuid;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketPartyKickRequest()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketPartyKickRequest(u32 InUuid)
	{
		Uuid = InUuid;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief シリアライズ
	 * @param[in] pStream ストリーム
	 * @return 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Uuid);
		
		return true;
	}
};

#endif		// #ifndef __PACKETPARTYKICKREQUEST_H__
