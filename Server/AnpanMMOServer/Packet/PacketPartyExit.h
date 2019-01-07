/**
 * @file PacketPartyExit.h
 * @brief パーティ離脱パケット
 * @author NativePacketGenerator
 */

#ifndef __PACKETPARTYEXIT_H__
#define __PACKETPARTYEXIT_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief パーティ離脱パケット
 */
class PacketPartyExit  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::PartyExit; }

	

	//! UUID
	u32 Uuid;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketPartyExit()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketPartyExit(u32 InUuid)
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

#endif		// #ifndef __PACKETPARTYEXIT_H__
