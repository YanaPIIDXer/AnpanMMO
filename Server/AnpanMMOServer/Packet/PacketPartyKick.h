/**
 * @file PacketPartyKick.h
 * @brief パーティメンバキック
 * @author NativePacketGenerator
 */

#ifndef __PACKETPARTYKICK_H__
#define __PACKETPARTYKICK_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief パーティメンバキック
 */
class PacketPartyKick  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @returns パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::PartyKick; }

	

	//! UUID
	u32 Uuid;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketPartyKick()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketPartyKick(u32 InUuid)
	{
		Uuid = InUuid;
		
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
		
		return true;
	}
};

#endif		// #ifndef __PACKETPARTYKICK_H__
