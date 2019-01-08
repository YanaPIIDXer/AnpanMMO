/**
 * @file PacketPartyExitRequest.h
 * @brief パーティ離脱リクエストパケット
 * @author NativePacketGenerator
 */

#ifndef __PACKETPARTYEXITREQUEST_H__
#define __PACKETPARTYEXITREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief パーティ離脱リクエストパケット
 */
class PacketPartyExitRequest  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::PartyExitRequest; }

	

	

	/**
	 * @brief コンストラクタ
	 */
	PacketPartyExitRequest()
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

#endif		// #ifndef __PACKETPARTYEXITREQUEST_H__
